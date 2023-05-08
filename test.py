import sys
import os
import pytest
import os.path
import pyperclip

code = None
inp = None
xpect = None
outp = None

@pytest.fixture(scope="session", autouse=True)
def setup():
    global code, inp, xpect, outp


    os.chdir(sys.argv[1])
    files = os.listdir(os.getcwd())
    for f in files:
        if f.endswith(".cc"):
            code = f
            path = os.path.abspath(f)
            pyperclip.copy(path)
            print(f"\nsource-path {path} copied to clipboard")
        elif f.endswith(".in"):
            inp = f
        elif f.endswith(".out") and f != "a.out":
            outp = f
        elif f.endswith(".xpect"):
            xpect = f

    assert code is not None
    assert inp is not None
    assert outp is not None
    assert xpect is not None



def run(flags, compiler='clang++', runner=""):

    ret = os.system(f"{compiler} -g {flags} -Werror {code}")
    assert ret == 0, "compilation error"
    ret = os.system(f"{runner} ./a.out")
    assert ret == 0, "runtime error"
    ret = os.system(f"diff {xpect} {outp}")
    assert ret == 0, "result is wrong"


def test_normal():
    run("")

# needs an instrumented libc++ to work correctly, worth it?
# https://github.com/google/sanitizers/wiki/MemorySanitizerLibcxxHowTo
# def test_memory():
#     run("-fsanitize=memory")

def test_undefined():
    run("-fsanitize=undefined")

def test_address():
    run("-fsanitize=address")

def test_O0():
    run("-O0")

def test_O2():
    run("-O2")

def test_gcc():
    run("-O2", compiler="g++")

def test_vg_memcheck():
    run("-O0", runner="valgrind -q")


if __name__ == "__main__":

    ret = pytest.main([__file__, "-s", "-vv", "-x", "--failed-first"])




