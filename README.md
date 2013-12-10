BTClient
========

This is C++ implementation for BTC-E.com API.

Dependencies
============

1. To prepare building environment you will need:
    - [autoconf](http://www.gnu.org/software/autoconf/);
    - [automake](http://www.gnu.org/software/automake/);
2. Also the program uses the following libraries:
    - [libcurl](http://curl.haxx.se/libcurl/) to work over HTTPS;
    - [libcrypto](http://www.openssl.org/docs/crypto/crypto.html) to compute
      message authentication codes;
    - [libjsoncpp](http://jsoncpp.sourceforge.net) to parse JSON responses from
      BTC-E.com.

Installation
============

1. Generate configure script:

        % aclocal
        % automake --add-missing
        % autoconf

2. Use configure script to generate make files:

        % ./configure

3. Build and install the program:

        % make
        # make install

After these steps btclient binary should be available for using.
