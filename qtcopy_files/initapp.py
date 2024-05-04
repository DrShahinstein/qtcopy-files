import os

DATA_DIR = "data"
TARGET_DIR_PATH = f"{DATA_DIR}/targetdir.txt"

def init_app():
    if not os.path.exists(DATA_DIR):
        os.makedirs(DATA_DIR)

    if not os.path.exists(TARGET_DIR_PATH):
        with open(TARGET_DIR_PATH, 'w') as f:
            f.write("select/target/dir")

__all__ = [TARGET_DIR_PATH, init_app]
