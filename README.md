# FT_container tester
## wi_container_tester

![](https://github.com/jsjohn1951/wi_container_tester/blob/main/graphics/visual_of_.gif)

wi_container_tester is a tester specifically designed to test your ft_containers project. Run the tester in a linux environment to check for memory leaks. The code within the directories can also be analysed to understand how containers (vector, map, stack(container adaptor) ) and their member functions can be used.

The grademe.sh bash scripts will generate both the ft:: containers and std:: containers in separate executables before comparing the outputs against each other. 

If the ft:: outputs aren't the same as the std:: outputs the functions get's KO'd and a difference is generated on the terminal using diff <(./std...) <(./ft...).

Upon compilation error when compiling the ./ft... executable, the function gets KO'd but no diff is shown. Instead there will be a compilation error msg.

Running the tester in a linux environment will automatically generate memleak checks and errors. If there are no memory leaks the leaks will be marked OK. The valgrind ERROR SUMMARY is also considered.

![](https://github.com/jsjohn1951/wi_container_tester/blob/main/graphics/Map_Test.png)

## Installation

Requires that git is installed on your machine.
Once git is installed, use the following command to clone the repo in the root directory of your ft_containers project.

```bash
git clone https://github.com/jsjohn1951/wi_container_tester.git
```

## Usage

Step 1 : change the directories inside of config.hpp. TAKE NOTE THE MACROS ARE RELATIVE TO THE TEST DIRECTORIES, NOT THE MAIN DIRECTORY! Add an extra "../" in front of the directory.

![](https://github.com/jsjohn1951/wi_container_tester/blob/main/graphics/config.png)

Step 2:

```bash
# enter ./grademe.sh followed by specific container/ or no arguments

# example:
./grademe.sh vector
./grademe.sh map
./grademe.sh stack

# To test all, leave out the argument
./grademe.sh

```
