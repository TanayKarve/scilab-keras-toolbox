sudo apt-get -y upgrade
sudo apt-get -y install python3.8 python3-pip python3.8-dev python3-distutils
echo "Installing Python dependenices..."
python3.8 -m pip install --upgrade pip
python3.8 -m pip install -r requirements.txt
export HDF5_DISABLE_VERSION_CHECK=1
echo "export HDF5_DISABLE_VERSION_CHECK=1" >> ~/.bashrc
