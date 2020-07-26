ANSI_RED=\033[31;1m
ANSI_GREEN=\033[32;1m
ANSI_YELLOW=\033[33;1m
ANSI_RESET=\033[0m

PHONY:=clean compile help valgrind
SILENT:=clean compile help valgrind

help: ## list make targets
	awk 'BEGIN {FS = ":.*?## "} /^[a-zA-Z_-]+:.*?## / {sub("\\\\n",sprintf("\n%22c"," "), $$2);printf " \033[36m%-20s\033[0m  %s\n", $$1, $$2}' $(MAKEFILE_LIST)

compile: *.c ## compile *.c source files
	$(MAKE) $(patsubst %.c,%,$?)

valgrind: compile *.c ## assess *.c source binaries
	for file in $(patsubst %.c,%,$(filter %.c,$?)); do \
		if valgrind --quiet --error-exitcode=1 --leak-check=full --undef-value-errors=no ./$${file} >> /dev/null 2>&1; then \
			echo "'$${file}' $(ANSI_GREEN)All heap blocks were freed -- no leaks are possible :)$(ANSI_RESET)"; \
		else \
			echo "'$${file}' $(ANSI_RED)Allocated heap blocks not freed -- memory leaks detected :($(ANSI_RESET)"; \
		fi \
	done

clean: *.c ## remove compile artefacts
	rm --force $(patsubst %.c,%,$?)

%: %.c
	$(CC) $(CFLAGS) $(LDFLAGS) -o $@ $@.c

.SILENT: $(SILENT)
.PHONY: $(PHONY)
