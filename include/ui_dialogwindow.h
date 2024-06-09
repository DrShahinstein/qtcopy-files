#ifndef UI_DIALOGWINDOW_H
#define UI_DIALOGWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>

QT_BEGIN_NAMESPACE

class UiDialogWindow {
public:
  QPushButton *btn_select_target_dir;
  QFrame *drag_n_drop_area;
  QLabel *drag_n_drop_label;
  QListWidget *files_view;
  QTextEdit *textedit_targetdir;
  QPushButton *btn_submit;
  QLineEdit *lineedit_target_dir;

  void setupUi(QDialog *Dialog) {
    if (Dialog->objectName().isEmpty())
      Dialog->setObjectName("Dialog");
    Dialog->resize(750, 520);
    btn_select_target_dir = new QPushButton(Dialog);
    btn_select_target_dir->setObjectName("btn_select_target_dir");
    btn_select_target_dir->setGeometry(QRect(220, 455, 360, 40));
    QFont font;
    font.setFamilies({QString::fromUtf8("Segoe Print")});
    font.setBold(true);
    font.setUnderline(true);
    btn_select_target_dir->setFont(font);
    btn_select_target_dir->setStyleSheet(
        QString::fromUtf8("QPushButton\n"
                          "{\n"
                          "border: none;\n"
                          "text-decoration: underline;\n"
                          "font-weight: bold;\n"
                          "color: rgb(255, 0, 0);\n"
                          "font-size: 20px;\n"
                          "}\n"
                          "\n"
                          "QPushButton:hover {\n"
                          "color: blue;\n"
                          "}"));
    drag_n_drop_area = new QFrame(Dialog);
    drag_n_drop_area->setObjectName("drag_n_drop_area");
    drag_n_drop_area->setGeometry(QRect(250, 80, 301, 131));
    drag_n_drop_area->setLayoutDirection(Qt::LayoutDirection::RightToLeft);
    drag_n_drop_area->setStyleSheet(
        QString::fromUtf8("QFrame {\n"
                          "  background-color: rgb(204, 204, 204);\n"
                          "  border-radius: 12px 0;\n"
                          "}\n"
                          "\n"
                          "QFrame:hover {\n"
                          "  opacity: 0.9;\n"
                          "}"));
    drag_n_drop_label = new QLabel(drag_n_drop_area);
    drag_n_drop_label->setObjectName("drag_n_drop_label");
    drag_n_drop_label->setGeometry(QRect(10, 10, 281, 111));
    drag_n_drop_label->setStyleSheet(QString::fromUtf8("QLabel\n"
                                                       "{\n"
                                                       "font-size: 21px;\n"
                                                       "}"));
    files_view = new QListWidget(Dialog);
    files_view->setObjectName("files_view");
    files_view->setGeometry(QRect(250, 260, 301, 131));
    files_view->setStyleSheet(
        QString::fromUtf8("QListView \n"
                          "{\n"
                          "background-color: transparent;\n"
                          "border: none;\n"
                          "}"));
    textedit_targetdir = new QTextEdit(Dialog);
    textedit_targetdir->setObjectName("textedit_targetdir");
    textedit_targetdir->setGeometry(QRect(290, 430, 221, 41));
    textedit_targetdir->setStyleSheet(
        QString::fromUtf8("QTextEdit {\n"
                          "  border: none;\n"
                          "  background: transparent;\n"
                          "}"));
    btn_submit = new QPushButton(Dialog);
    btn_submit->setObjectName("btn_submit");
    btn_submit->setGeometry(QRect(250, 210, 301, 31));
    btn_submit->setStyleSheet(
        QString::fromUtf8("QPushButton\n"
                          "{\n"
                          "background-color: rgb(8, 180, 42);\n"
                          "color: white;\n"
                          "font-weight: bold;\n"
                          "}"));
    lineedit_target_dir = new QLineEdit(Dialog);
    lineedit_target_dir->setObjectName("lineedit_target_dir");
    lineedit_target_dir->setGeometry(QRect(250, 50, 301, 31));

    retranslateUi(Dialog);

    QMetaObject::connectSlotsByName(Dialog);
  } // setupUi

  void retranslateUi(QDialog *Dialog) {
    Dialog->setWindowTitle(
        QCoreApplication::translate("Dialog", "Dialog", nullptr));
    btn_select_target_dir->setText(
        QCoreApplication::translate("Dialog", "select/target/dir", nullptr));
    drag_n_drop_label->setText(QCoreApplication::translate(
        "Dialog",
        "<html><head/><body><p align=\"center\">Drag &amp; Drop "
        "Files</p></body></html>",
        nullptr));
    textedit_targetdir->setHtml(QCoreApplication::translate(
        "Dialog",
        "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" "
        "\"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
        "<html><head><meta name=\"qrichtext\" content=\"1\" /><meta "
        "charset=\"utf-8\" /><style type=\"text/css\">\n"
        "p, li { white-space: pre-wrap; }\n"
        "hr { height: 1px; border-width: 0; }\n"
        "li.unchecked::marker { content: \"\\2610\"; }\n"
        "li.checked::marker { content: \"\\2612\"; }\n"
        "</style></head><body style=\" font-family:'Sans Serif'; "
        "font-size:9pt; font-weight:400; font-style:normal;\">\n"
        "<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; "
        "margin-left:0px; margin-right:0px; -qt-block-indent:0; "
        "text-indent:0px;\"><span style=\" font-family:'Segoe UI'; "
        "font-size:14pt;\">Target Directory:</span></p></body></html>",
        nullptr));
    btn_submit->setText(QCoreApplication::translate("Dialog", "OK", nullptr));
    lineedit_target_dir->setText(QString());
  } // retranslateUi
};

QT_END_NAMESPACE

#endif // DIALOGWINDOW_H
