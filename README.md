# Basic_Doxygen_Auto_Run
This repository will explain auto run using Doxygen on Platformio to make documentation easier.

# Pretime-Setup
1. [Install Doxygen](https://www.doxygen.nl/manual/install.html)
2. install extension `Platformio` in `VSCode` for embeded tools.

# Flow Run Time Project
1. edit your code that will be doxygenized in the `./src` or `./lib` file, such as adding headers of class, headers of function, and others.
2. edit line 15 and line 16 based on `commandRunDoxygen.py` in your directory project.
3. If you want to add a new doxygen file, you can give the command `"doxygen -f [your-file-name]"`.
4. edit the doxygen file as needed. The following are examples of existing changes. 
```    
    PROJECT_NAME           = "Example Doxygen in PlatformIO"
    PROJECT_NUMBER         = 0.1
    OUTPUT_DIRECTORY       = ./docs
    INPUT                  = ./src ./lib
    RECURSIVE              = YES
    EXTRACT_ALL            = YES
    EXTRACT_PRIVATE        = YES
    EXTRACT_STATIC         = YES
    GENERATE_LATEX         = NO
    GENERATE_HTML          = YES
    HTML_OUTPUT            = html
```
5. on line 22 in `platformio.ini` namely `extra_scripts` set `pre` or `post` the program build.
