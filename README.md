# zipop
A cli tool made in C that allows you to generate a massively compressed file
# usage
```
zipop -s [size] [options] -o [filename]
```
# requirements
This tools requires you to have [dd](https://en.wikipedia.org/wiki/Dd_%28Unix%29) and [gzip2](https://en.wikipedia.org/wiki/Bzip2) in order to work
# compiling and installation
```
git clone https://github.com/Synth9283/zipop.git
cd zipop
make
make install
```
# uninstalling
```
make uninstall
```
Manual Uninstall:
```
rm -fv /usr/bin/zipop
```
# usage on Windows
To use this tool on Windows, it would require for you to have WSL installed

