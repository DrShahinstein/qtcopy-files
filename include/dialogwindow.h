#ifndef DIALOGWINDOW_H
#define DIALOGWINDOW_H

#include "ui_dialogwindow.h"

#define LISTWIDGET_QSS "QListWidget { background-color: transparent; border: none; font-size: 10px; }"

class DialogWindow : public QDialog, public UiDialogWindow {
  Q_OBJECT

public:
  DialogWindow(QWidget *parent = nullptr);

protected:
  bool eventFilter(QObject *obj, QEvent *event) override;

private slots:
  void get_target_dir();
  void move_files();

private:
  QStringList incoming_files;
};

#endif // DIALOGWINDOW_H
