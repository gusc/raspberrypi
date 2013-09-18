SECTIONS {
	. = 0x8000;
	.text : {
		*(.init);
		*(.text);
	}
	. = ALIGN(4096);
	.rodata : { 
		*(.rodata);
	}
	. = ALIGN(4096);
	.data : { 
		*(.data);
	}
	. = ALIGN(4096);
	_bss_start = .;
	.bss : {
		*(.bss);
	}
	. = ALIGN(4096);
	_bss_end = .;
}