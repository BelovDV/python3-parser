INPUT_FILES = tmp/output.csv example/input.py example/second.py example/simple.py

all:

.PHONY: build
build: tmp/antlr
	mkdir -p tmp/build
	cd tmp/build ; cmake ../.. ; make

.PHONY: run
run: build
	tmp/build/antlr_python_parser ${INPUT_FILES}

.PHONY: dev
dev: _clear run


.PHONY: antlr_force
antlr_force: tmp
	mkdir -p tmp/antlr
	cp Python3.g4 tmp/antlr/Python3.g4
	cd tmp/antlr ; java -jar /usr/local/lib/antlr-4.9-complete.jar -Dlanguage=Cpp Python3.g4 -visitor

tmp/antlr: tmp
	mkdir -p tmp/antlr
	cp Python3.g4 tmp/antlr/Python3.g4
	cd tmp/antlr ; java -jar /usr/local/lib/antlr-4.9-complete.jar -Dlanguage=Cpp Python3.g4 -visitor

.PHONY: _clear
_clear:
	@clear

tmp:
	mkdir -p tmp

.PHONY: clean
clean:
	rm -rf antlr
