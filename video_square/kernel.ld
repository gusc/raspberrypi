SECTIONS {
	.init 0x8000 : {
		*(.init)
	}
	.text : { 
		*(.text);
	}
	.rodata : { 
		*(.rodata);
	}
	.data : { 
		*(.data);
	}
	.bss : {
		*(.bss);
	}
	/DISCARD/ : {
		*(*)
	}
	. = ALIGN(4096);
}