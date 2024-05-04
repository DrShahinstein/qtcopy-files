from PySide6.QtWidgets import QApplication, QMainWindow, QFileDialog, QListWidgetItem, QMessageBox
from PySide6.QtGui import QDragEnterEvent, QDropEvent
from PySide6.QtCore import Qt
from qtcopy_files.mainwindow import Ui_MainWindow
from qtcopy_files.initapp import TARGET_DIR_PATH, init_app
import sys
import shutil
import os


LISTWIDGET_QSS = """
            QListWidget {
                background-color: transparent;
                border: none;
                font-size: 10px;
            }
        """


def get_current_target_dir() -> str:
    with open(TARGET_DIR_PATH, "r") as f:
        return f.read()


class CenterAlignedListWidgetItem(QListWidgetItem):
    def __init__(self, text):
        super().__init__(text)
        self.setTextAlignment(Qt.AlignCenter)


class MainWindow(QMainWindow):
    incoming_files = []

    def __init__(self):
        super().__init__()
        self.ui = Ui_MainWindow()
        self.ui.setupUi(self)

        self.ui.drag_n_drop_area.setAcceptDrops(True)

        self.ui.btn_select_target_dir.setText(get_current_target_dir())
        self.ui.btn_select_target_dir.setCursor(Qt.CursorShape.PointingHandCursor)

        self.ui.btn_select_target_dir.clicked.connect(self.get_target_dir)
        self.ui.btn_submit.clicked.connect(self.move_files)

        self.ui.files_view.setStyleSheet(LISTWIDGET_QSS)

    def get_target_dir(self):
        self.target_path = QFileDialog.getExistingDirectory(
            self, "Select Directory")

        if self.target_path:
            self.ui.btn_select_target_dir.setText(self.target_path)
            with open(TARGET_DIR_PATH, "w") as f:
                f.write(self.target_path)

    def move_files(self):
        target_dir = get_current_target_dir()

        for f in self.incoming_files:
            fname = os.path.basename(f)
            fdest = os.path.join(target_dir, fname)

            try:
                if os.path.isdir(f):
                    shutil.copytree(f, fdest)
                else:
                    shutil.copy(f, fdest)
            except Exception as e:
                error_message = f"Error copying '{fname}' to '{target_dir}'\n\n{e}"
                QMessageBox.critical(self, "Error", error_message)
            finally:
                self.incoming_files = []
                self.ui.files_view.clear()

    def dragEnterEvent(self, e: QDragEnterEvent) -> None:
        if e.mimeData().hasUrls():
            e.accept()
        else:
            e.ignore()

    def dropEvent(self, e: QDropEvent) -> None:
        if e.mimeData().hasUrls():
            urls = e.mimeData().urls()

            for url in urls:
                file = url.toLocalFile()  # file as path
                if file not in self.incoming_files:
                    self.incoming_files.append(file)
                    list_item = CenterAlignedListWidgetItem(file)
                    self.ui.files_view.addItem(list_item)
        else:
            e.ignore()


def main():
    init_app()
    app = QApplication(sys.argv)
    widget = MainWindow()
    widget.setWindowTitle("Drag & Drop Files")
    widget.show()
    sys.exit(app.exec())
