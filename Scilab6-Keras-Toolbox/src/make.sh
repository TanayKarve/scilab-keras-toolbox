gcc  -fPIC -I/usr/include/python3.8 $(python3.8-config --cflags) -c c_transfer.c  
gcc -lpython3.8 $(python3.8-config --ldflags) -Xlinker -export-dynamic -fPIE  -shared -o libscikeras.so c_transfer.o
gcc -I/usr/include/python3.8     -L$(pwd) -Wl,-rpath=$(pwd) -o test main.c -lscikeras -lpython3.8 -g
echo "Copy libscikeras.so to thirdparty/linux/lib/x64/"
#cp libscikeras.so thirdparty/linux/lib/x64/


