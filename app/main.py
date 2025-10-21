# ------------------------------------------------------------------------------- #
# IMPORTS
# ------------------------------------------------------------------------------- #

import sys
import importlib
import importlib.util
from types import ModuleType
from pathlib import Path

# ------------------------------------------------------------------------------- #
# MODULE LOAD
# ------------------------------------------------------------------------------- #

def is_module_system_loaded(name=''):
    return importlib.util.find_spec(name) is not None


def import_directory(debug=True):
    path = Path(__file__).resolve().parent.parent
    return path.joinpath("build", "Debug" if debug else "Release")


def load_module(name='', debug=True):
    if is_module_system_loaded(name):
        module = importlib.import_module(name)
        if isinstance(module, ModuleType):
            return module
    module_dir = import_directory(debug)
    if not module_dir.is_dir():
        print(f"ERROR : Module Import Directory : Not a directory : {module_dir}")
        return None
    module_dir = str(module_dir)
    if module_dir not in sys.path:
        sys.path.insert(0, module_dir)
    try:
        module = importlib.import_module(name)
        if isinstance(module, ModuleType):
            print(f"SUCCESS : Module Imported : {name}")
            return module
    except ModuleNotFoundError as e:
        print(f"ERROR : Module Not Imported : {name} : {e}")
    return None

# ------------------------------------------------------------------------------- #
# CALLBACKS
# ------------------------------------------------------------------------------- #

def update():
    pass


def draw_3d():
    pass


def draw_2d():
    pass

# ------------------------------------------------------------------------------- #
# MAIN
# ------------------------------------------------------------------------------- #

def main():
    KCE = load_module(name='KCE', debug=True)
    if KCE:
        window = KCE.Window(700, 500, "KenzoCG-Engine", update, draw_3d, draw_2d)
        window.run()

if __name__ == "__main__":
    main()
