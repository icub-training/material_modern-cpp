

# The environment

We need an environment where to run our exercises. As they come with `Cmake` there are several possibilities. We propose two:

- a  `gitpod` environment ready to use with `Visual Studio Code`,
- a `Ubuntu` 2022.04 environment in `WSL2` with `Visual Studio Code`.



In the following are basic instructions for preparing these two environments.



## Setting up `gitpod`



This environment is ready to use and requires only a browser. Instructions of its use are in here.

In here are instructions about how to use `gitpod`



1. log in

   ![gitpod-20240502124437655](./environment.assets/gitpod-20240502124437655.png)

2. then open a workspace w/ CTRL + O. Open your forked repository: `https://github.com/marcoaccame/material_modern-cpp`

   ![gitpod-20240502124625222](./environment.assets/gitpod-20240502124625222.png)

   ![gitpod-20240502124750209](./environment.assets/gitpod-20240502124750209.png)

4. after some preparation your environment will appear

   ![gitpod-20240502124825230](./environment.assets/gitpod-20240502124825230.png)

   ![gitpod-20240502124929404](./environment.assets/gitpod-20240502124929404.png)

5. use it for:

   - visualizing .md files
     ![gitpod-20240502125329746](./environment.assets/gitpod-20240502125329746.png)
   
   - for compiling and running code
   
     ![gitpod-20240502125505301](./environment.assets/gitpod-20240502125505301.png)
   
     ![gitpod-20240502125543161](./environment.assets/gitpod-20240502125543161.png)
   
     ![gitpod-20240502125615560](./environment.assets/gitpod-20240502125615560.png)
   
     ![gitpod-20240502125640364](./environment.assets/gitpod-20240502125640364.png)
   
   - for debugging
   
     ![gitpod-20240502125751441](./environment.assets/gitpod-20240502125751441.png)
   
     ![gitpod-20240502125916736](./environment.assets/gitpod-20240502125916736.png)
   
     ![gitpod-20240502130000147](./environment.assets/gitpod-20240502130000147.png)
   
     



## Setting up `Ubuntu`

This section will show how to setup the Ubuntu 20.04 environment for WSL2 in Windows. Similar settings apply to a native Ubuntu distribution.

The steps are:

- install Ubuntu 20.04 on WSL2
- install the development tools required to compile
- install and configure Visual Studio Code to run the debugger.

### Install Ubuntu on WSL2

TBD

### Install the compilation tools

The following are required
- `git`

  ```bash
  $ sudo apt install git -y
  $ git --version
  ```

- `cmake`

  ```bash
  $ sudo apt  install cmake
  $ cmake --version
  ```

- `ccmake`

  ```bash
  $ sudo apt install cmake-curses-gui
  $ ccmake --version
  ```
- `gcc` et al (gcc, g++ and make)

  ```bash
  $ sudo apt install build-essential
  $ gcc --version
  $ g++ --version
  $ make --version
  ```
  
- `gdb`

  ```bash
  $ sudo apt install gdb
  $ gdb --version
  ```

- `others`: tree, meld
  
  ```bash
  $ sudo apt install tree
  $ sudo apt install meld
  ```



### Install and launch VSC

Visual Studio Code can be installed either on windows via the Microsoft store or directly on Ubuntu. Then it can started from Ubuntu (but also from Windows).

See the following installation instructions:

- `Ubuntu`: https://code.visualstudio.com/docs/setup/linux
- `Windows`: https://code.visualstudio.com/docs/setup/windows



On Linux we start it w/ following command

  ```bash
  $ code
  ```



![image-20240509085920480](./environment.assets/image-20240509085920480.png)



### Configure VSC

After we launch it we must configure it for using with C++ and for debugging with GDB, so we need to install the following extensions suggested by https://code.visualstudio.com/docs/languages/cpp. See also https://code.visualstudio.com/docs/cpp/cpp-debug.

- `ms-vscode.cpptools-extension-pack`

  ![image-20240509091038855](./environment.assets/image-20240509091038855.png)

- `ms-vscode-remote.remote-wsl`

  ![image-20240509091257444](./environment.assets/image-20240509091257444.png)



The above should be enough. However, it is important to:

- connect to wsl2 w/ CTRL + ALT + O

  ![image-20240509091911828](./environment.assets/image-20240509091911828.png)

- make sure that the extensions are enabled also in wsl2.

  ![image-20240509091817370](./environment.assets/image-20240509091817370.png)

  ![image-20240509091840882](./environment.assets/image-20240509091840882.png)

  
