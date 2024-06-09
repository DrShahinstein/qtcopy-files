#include "dialogwindow.h"
#include "initapp.h"
#include <QDir>
#include <QDragEnterEvent>
#include <QFile>
#include <QFileDialog>
#include <QFileInfo>
#include <QListWidgetItem>
#include <QMessageBox>
#include <QMimeData>
#include <QString>
#include <QtCore/Qt>

QString get_current_target_dir() {
  QString target_dir;
  QFile f(TARGET_DIR_PATH);

  if (f.open(QIODevice::ReadOnly | QIODevice::Text)) {
    QTextStream in(&f);
    target_dir = in.readLine();
    f.close();
  }

  return target_dir;
}

void copy_path(QString src, QString dst) {
  QDir dir(src);
  if (!dir.exists())
    return;

  foreach (QString d, dir.entryList(QDir::Dirs | QDir::NoDotAndDotDot)) {
    QString dst_path = dst + QDir::separator() + d;
    dir.mkpath(dst_path);
    copy_path(src + QDir::separator() + d, dst_path);
  }

  foreach (QString f, dir.entryList(QDir::Files)) {
    QFile::copy(src + QDir::separator() + f, dst + QDir::separator() + f);
  }
}

DialogWindow::DialogWindow(QWidget *parent) : QDialog(parent) {
  setupUi(this);

  lineedit_target_dir->setPlaceholderText("Enter a directory name to wrap dropped files up");
  drag_n_drop_area->setCursor(Qt::CursorShape::PointingHandCursor);
  drag_n_drop_area->setAcceptDrops(true);
  drag_n_drop_area->installEventFilter(this);
  btn_select_target_dir->setText(get_current_target_dir());
  btn_select_target_dir->setCursor(Qt::CursorShape::PointingHandCursor);

  connect(btn_select_target_dir, &QPushButton::clicked, this, &DialogWindow::get_target_dir);
  connect(btn_submit, &QPushButton::clicked, this, &DialogWindow::move_files);

  files_view->setStyleSheet(LISTWIDGET_QSS);
}

void DialogWindow::get_target_dir() {
  QString target_path = QFileDialog::getExistingDirectory(
      this, "Select Directory", QDir::currentPath());

  if (!target_path.isEmpty()) {
    if (btn_select_target_dir) {
      btn_select_target_dir->setText(target_path);
    }

    QFile file(TARGET_DIR_PATH);
    if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {
      QTextStream out(&file);
      out << target_path;
      file.close();
    } else {
      qWarning() << "Error writing to file:" << TARGET_DIR_PATH;
    }
  }
}

void DialogWindow::move_files() {
  QString target_dir = get_current_target_dir();

  QDir td(target_dir);
  if (!td.exists()) {
    QMessageBox::critical(this, "Error", "Target directory does not exist.");
    return;
  }

  QString wrapping_dir_name = lineedit_target_dir->text().isEmpty()
                                  ? DEFAULT_WRAPPING_DIR
                                  : lineedit_target_dir->text();

  QString wrapping_dir_path =
      target_dir + QDir::separator() + wrapping_dir_name;
  QDir wrdir(wrapping_dir_path);
  if (!wrdir.exists()) {
    wrdir.mkdir(wrapping_dir_path);
  }

  for (const QString &f : incoming_files) {
    QFileInfo file_info(f);
    QString fname = file_info.fileName();
    QString fdest = wrapping_dir_path + QDir::separator() + fname;

    try {
      if (file_info.isDir()) {
        QDir().mkpath(fdest);
        copy_path(f, fdest);
      } else {
        QFile::copy(f, fdest);
      }
    } catch (const std::exception &e) {
      QString error_message = QString("Error copying '%1' to '%2'\n\n%3")
                                  .arg(fname)
                                  .arg(target_dir)
                                  .arg(e.what());
      QMessageBox::critical(this, "Error", error_message);
    }
  }

  incoming_files.clear();
  files_view->clear();
}

bool DialogWindow::eventFilter(QObject *obj, QEvent *event) {
  if (event->type() == QEvent::DragEnter) {
    QDragEnterEvent *dragEvent = static_cast<QDragEnterEvent *>(event);
    if (dragEvent->mimeData()->hasUrls()) {
      dragEvent->acceptProposedAction();
      return true;
    }
  } else if (event->type() == QEvent::Drop) {
    QDropEvent *dropEvent = static_cast<QDropEvent *>(event);
    if (dropEvent->mimeData()->hasUrls()) {
      QList<QUrl> urls = dropEvent->mimeData()->urls();
      for (const QUrl &url : urls) {
        QString file = url.toLocalFile();
        if (!incoming_files.contains(file)) {
          incoming_files.append(file);
          QListWidgetItem *list_item = new QListWidgetItem(file);
          files_view->addItem(list_item);
        }
      }
      return true;
    }
  }
  return QDialog::eventFilter(obj, event);
}
