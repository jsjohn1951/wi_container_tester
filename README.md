# FT_container tester
## wi_container_tester

wi_container_tester is a tester specifically designed to test your ft_container project. The code within the directories can also be analysed to understand how containers (vector, map, stack(container adaptor) ) can be used.

The grademe.sh bash scripts will generate both the ft:: containers and std:: containers in separate executables before comparing the outputs against each other. 

If the ft:: outputs aren't the same as the std:: the function get's KO'd and a difference is generated on the terminal using diff <(./std...) <(./ft...).

Upon compilation error when compiling the ./ft... executable, the function gets KO'd but no diff is shown. Instead there will be a compilation error msg.

## Installation

Requires that git is installed on your machine.
Once git is installed, use the following command to clone the repo in the root directory of your ft_containers project.

```bash
git clone https://github.com/jsjohn1951/wi_container_tester.git
```

## Usage

Step 1 : change the directories inside of config.hpp. TAKE NOTE THE MACROS ARE RELATIVE TO THE TEST DIRECTORIES, NOT THE MAIN DIRECTORY! Add an extra "../" in front of the directory.

Step 2:

```bash
# enter ./grademe.sh followed by specific container/ or no arguments

# example:
./grademe.sh vector
./grademe.sh map

# To test all, leave out the argument
./grademe.sh

```

## Support

Test support most functions in vector, including vector iterators. More tests will be added.

Test supports some functions in map, but does not test map completely yet. More tests will be added.

Stack tests will be added.

Please make sure to update tests as appropriate, as tester is still under development.

## License

Open Source