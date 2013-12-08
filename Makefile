build:
	clang++ -Wall -g -o btclient \
		-I/opt/local/include -L/opt/local/lib \
		-lcurl -lssl -lcrypto -ljsoncpp \
		crypto.cc http.cc json.cc btclient.cc main.cc
clean:
	rm -rf btclient btclient.dSYM
