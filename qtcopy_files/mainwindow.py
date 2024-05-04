from PySide6 import QtCore, QtGui, QtWidgets


class Ui_MainWindow(object):
    def setupUi(self, MainWindow):
        MainWindow.setObjectName("MainWindow")
        MainWindow.resize(800, 600)
        MainWindow.setLayoutDirection(QtCore.Qt.LayoutDirection.RightToLeft)
        self.centralwidget = QtWidgets.QWidget(parent=MainWindow)
        self.centralwidget.setObjectName("centralwidget")
        self.btn_select_target_dir = QtWidgets.QPushButton(
            parent=self.centralwidget)
        self.btn_select_target_dir.setGeometry(QtCore.QRect(10, 540, 781, 41))
        font = QtGui.QFont()
        font.setFamily("Segoe Print")
        font.setPointSize(1)
        font.setBold(True)
        font.setUnderline(True)
        self.btn_select_target_dir.setFont(font)
        self.btn_select_target_dir.setStyleSheet("QPushButton\n"
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
                                                 "}")
        self.btn_select_target_dir.setObjectName("btn_select_target_dir")
        self.text_tardir = QtWidgets.QTextEdit(parent=self.centralwidget)
        self.text_tardir.setGeometry(QtCore.QRect(320, 510, 161, 41))
        self.text_tardir.setStyleSheet("QTextEdit {\n"
                                       "  border: none;\n"
                                       "  background: transparent;\n"
                                       "}")
        self.text_tardir.setObjectName("text_tardir")
        self.btn_submit = QtWidgets.QPushButton(parent=self.centralwidget)
        self.btn_submit.setGeometry(QtCore.QRect(260, 250, 301, 31))
        self.btn_submit.setStyleSheet("QPushButton\n"
                                      "{\n"
                                      "background-color: rgb(8, 180, 42);\n"
                                      "color: white;\n"
                                      "font-weight: bold;\n"
                                      "}")
        self.btn_submit.setObjectName("btn_submit")
        self.drag_n_drop_area = QtWidgets.QFrame(parent=self.centralwidget)
        self.drag_n_drop_area.setGeometry(QtCore.QRect(260, 110, 301, 131))
        self.drag_n_drop_area.setLayoutDirection(
            QtCore.Qt.LayoutDirection.RightToLeft)
        self.drag_n_drop_area.setStyleSheet("QFrame {\n"
                                            "  background-color: rgb(204, 204, 204);\n"
                                            "  border-radius: 10px;\n"
                                            "}\n"
                                            "\n"
                                            "QFrame:hover {\n"
                                            "opacity: 0.9;\n"
                                            "}")
        self.drag_n_drop_area.setObjectName("drag_n_drop_area")
        self.drag_n_drop_label = QtWidgets.QLabel(parent=self.drag_n_drop_area)
        self.drag_n_drop_label.setGeometry(QtCore.QRect(10, 10, 281, 111))
        self.drag_n_drop_label.setStyleSheet("QLabel\n"
                                             "{\n"
                                             "font-size: 21px;\n"
                                             "}")
        self.drag_n_drop_label.setObjectName("drag_n_drop_label")
        self.files_view = QtWidgets.QListWidget(parent=self.centralwidget)
        self.files_view.setGeometry(QtCore.QRect(260, 300, 301, 140))
        self.files_view.setStyleSheet("QListView \n"
                                      "{\n"
                                      "background-color: transparent;\n"
                                      "border: none;\n"
                                      "}")
        self.files_view.setObjectName("files_view")
        MainWindow.setCentralWidget(self.centralwidget)

        self.retranslateUi(MainWindow)
        QtCore.QMetaObject.connectSlotsByName(MainWindow)

    def retranslateUi(self, MainWindow):
        _translate = QtCore.QCoreApplication.translate
        MainWindow.setWindowTitle(_translate("MainWindow", "MainWindow"))
        self.btn_select_target_dir.setText(
            _translate("MainWindow", "select/target/dir"))
        self.text_tardir.setHtml(_translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
                                            "<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
                                            "p, li { white-space: pre-wrap; }\n"
                                            "hr { height: 1px; border-width: 0; }\n"
                                            "li.unchecked::marker { content: \"\\2610\"; }\n"
                                            "li.checked::marker { content: \"\\2612\"; }\n"
                                            "</style></head><body style=\" font-family:\'Segoe UI\'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
                                            "<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:14pt;\">Target Directory:</span></p></body></html>"))
        self.btn_submit.setText(_translate("MainWindow", "OK"))
        self.drag_n_drop_label.setText(_translate(
            "MainWindow", "<html><head/><body><p align=\"center\">Drag &amp; Drop Files</p></body></html>"))


if __name__ == "__main__":
    import sys
    app = QtWidgets.QApplication(sys.argv)
    MainWindow = QtWidgets.QMainWindow()
    ui = Ui_MainWindow()
    ui.setupUi(MainWindow)
    MainWindow.show()
    sys.exit(app.exec())
