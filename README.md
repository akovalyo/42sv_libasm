# 42sv_Libasm

The aim of the project is to get familiar with assembly language.


## Installing NASM under Unix

Once you've obtained the Unix source archive for NASM, nasm-XXX.tar.gz (where XXX denotes the version number of NASM contained in the archive), unpack it into a directory such as /usr/local/src. The archive, when unpacked, will create its own subdirectory nasm-XXX.

NASM is an auto-configuring package: once you've unpacked it, cd to the directory it's been unpacked into and type ./configure. This shell script will find the best C compiler to use for building NASM and set up Makefiles accordingly.

Once NASM has auto-configured, you can type make to build the nasm and ndisasm binaries, and then make install to install them in /usr/local/bin and install the man pages nasm.1 and ndisasm.1 in /usr/local/man/man1. Alternatively, you can give options such as --prefix to the configure script (see the file INSTALL for more details), or install the programs yourself.

NASM also comes with a set of utilities for handling the RDOFF custom object-file format, which are in the rdoff subdirectory of the NASM archive. You can build these with make rdf and install them with make rdf_install, if you want them.
