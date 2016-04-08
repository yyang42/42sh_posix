umask 777
umask
umask a+= # Equivalent to a+, a=; clears all file mode bits.
umask
umask go+-w # Equivalent to go+, go- w; clears group and other write bits.
umask
umask g=o-w # Equivalent to g= o, g- w; sets group bit to match other bits and then clears group write bit.
umask
umask g-r+w # Equivalent to g- r, g+ w; clears group read bit and sets group write bit.
umask
umask uo=g # Sets owner bits to match group bits and sets other bits to match group bits.
umask
