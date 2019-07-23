import os
import subprocess

print("started")
testdirectory = "test"    
tempfilename = "tmp"
filename = "ex1"
exename = "a.out"

with open(f"{filename}.icl", "r") as read_file:
    contents = read_file.read()

if not os.path.exists(testdirectory):
    os.makedirs(testdirectory)

contents = contents.replace("\n Start", "//Start")
contents = contents.replace("\nStart", "//Start")

def make_call(command):
    out, err = subprocess.Popen(command.split(" ")).communicate()
    return out

def create_test_file(function, arguments):
    with open(f"{testdirectory}/{filename}.icl", 'w+') as testfile:
        testfile.write(contents)
        testfile.write(f"\nStart = {function} {arguments}")

with open(tempfilename, 'w') as write_file:
    write_file.write(contents)

def main():
    create_test_file("factor", "5")
    make_call(f"clm -l -no-pie -I {testdirectory} {filename} -o {testdirectory}/{exename}")
    exepath = f"./{testdirectory}/{exename}"
# TODO can do this with err return of make_call
    if os.path.exists(exepath):
        output = make_call(exepath)
        print(output)
        print(output.split("\n"))
    else:
        print("there was an error during compilation")

main()
