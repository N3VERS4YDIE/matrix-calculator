import os


def verify_dirs(*dirs):
    for _dir in dirs:
        if not os.path.isdir(_dir):
            os.mkdir(_dir)


def build(project_name, *sources):
    object_files = ""
    for source in sources:
        os.system(f"g++ -std=c++11 -Wall -O3 -c src/{source}.cpp -o build/{source}.o")
        object_files += f"build/{source}.o "
    os.system(f"g++ {object_files} -o bin/{project_name}")


verify_dirs("build", "bin")
build("matrix-calculator", "matrix", "main")
