***How to launch a website***

1. Move to the home directory of the current user
```Bash
cd ~
```
2. Copy this repository
```Bash
git clone https://github.com/Amongety/WebSiteStarryTribe.git
```
3. Install the Boost library

4. Install the Wt library
```Bash
git clone https://github.com/emweb/wt.git
```
4.1. Create a build directory
```Bash
cd wt-x.x.x
mkdir build
cd build
```
4.2. Configure the library
```Bash
cmake ../
```
4.3. Build the library
```Bash
make
```
4.4. Install the library
```Bash
sudo make install
```
