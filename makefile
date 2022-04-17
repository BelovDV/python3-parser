all:

.PHONY: build
build: tmp/antlr
	mkdir -p tmp/build
	cd tmp/build ; cmake ../.. ; make

.PHONY: run
run: build
	tmp/build/antlr_python_parser

tmp/antlr: tmp
	mkdir -p tmp/antlr
	cp Python3.g4 tmp/antlr/Python3.g4
	cd tmp/antlr ; java -jar /usr/local/lib/antlr-4.9-complete.jar -Dlanguage=Cpp Python3.g4 -visitor -no-listener

tmp:
	mkdir -p tmp

.PHONY: clean
clean:
	rm -rf antlr
