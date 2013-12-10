BTClient
========

This is C++ implementation for BTC-E.com API.


Dependencies
============

1) To prepare building environment you will need:
    - autoconf [1];
    - automake [2];

2) Also the program uses the following libraries:
    - libcurl [3] to work over HTTPS;
    - libcrypto [4] to compute message authentication codes;
    - libjsoncpp [5] to parse JSON responses from BTC-E.com;

[1] http://www.gnu.org/software/autoconf/
[2] http://www.gnu.org/software/automake/
[3] http://curl.haxx.se/libcurl/
[4] http://www.openssl.org/docs/crypto/crypto.html
[5] http://jsoncpp.sourceforge.net


Installation
============

1) Generate configure script:
    % aclocal
    % automake --add-missing
    % autoconf

2) Use configure script to generate make files:
    % ./configure

3) Build and install the program:
    % make
    # make install

After these steps btclient binary should be available for using.
