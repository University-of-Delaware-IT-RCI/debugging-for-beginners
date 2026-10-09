
simple.x:     file format elf64-x86-64


Disassembly of section .text:

0000000000401126 <main>:
  401126:	55                   	push   %rbp
  401127:	48 89 e5             	mov    %rsp,%rbp
  40112a:	c7 45 f8 04 00 00 00 	movl   $0x4,-0x8(%rbp)
  401131:	c7 45 f4 0a 00 00 00 	movl   $0xa,-0xc(%rbp)
  401138:	c7 45 fc 00 00 00 00 	movl   $0x0,-0x4(%rbp)
  40113f:	eb 0a                	jmp    40114b <main+0x25>
  401141:	8b 45 f4             	mov    -0xc(%rbp),%eax
  401144:	01 45 f8             	add    %eax,-0x8(%rbp)
  401147:	83 45 fc 01          	addl   $0x1,-0x4(%rbp)
  40114b:	83 7d fc 03          	cmpl   $0x3,-0x4(%rbp)
  40114f:	7e f0                	jle    401141 <main+0x1b>
  401151:	8b 45 f8             	mov    -0x8(%rbp),%eax
  401154:	5d                   	pop    %rbp
  401155:	c3                   	ret    
