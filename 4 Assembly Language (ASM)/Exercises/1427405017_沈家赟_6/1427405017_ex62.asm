;-----------------------------------------
;EX62
;1427405017
;沈家赟
;-----------------------------------------
;6.7   请编写程序ex62实现如下功能：
; 由用户从键盘输入一个十进制数的字符串；
; 随后，将其转换成数值；
; 然后，把该数值转换成对应十六进制数的字符串；
; 最后输出十六进制数的字符串。
; 请设计合适的子程序。

; 假设数值采用32位足够表示；
; 假设用户输入的十进制数字串肯定有效合法。
;-----------------------------------------
	segment   ex62      ;命名段ex62
    org   100H          ;段内偏移从100H开始计算
    ;
    MOV   AX, CS
    MOV   DS, AX        ;使数据段与代码段相同
    ;
    MOV   DX, note     ;准备PUT_STR入口参数：DX=note的段内偏移
    CALL PUT_STR
    ;
	XOR DI, DI
	MOV DI, str_in
	CALL GET_STR	;键盘输入字符串
	;
	CALL NEW_LINE	;显示换行
	CALL NEW_LINE	;显示换行
	;
	MOV DX, note_str_in
	CALL PUT_STR
	MOV   DX, str_in     ;准备PUT_STR入口参数：DX=str_in的段内偏移
	CALL PUT_STR	;显示字符串，验证内存域已被输入
	CALL NEW_LINE
	
	;
	MOV ESI, str_in
	CALL CONVERT_STR_TO_INT		;调用CONVERT_STR_TO_INT
	MOV [num_dec], EAX
	;
	MOV EAX, [num_dec]
	MOV EDI, str_hex
	CALL CONVERT_INT_TO_HEX		;调用CONVERT_INT_TO_HEX
	;
	CALL NEW_LINE
	;
	MOV EAX, [num_dec]
	MOV EDI, str_dec
	CALL CONVERT_INT_TO_STR		;调用CONVERT_INT_TO_STR
	;
	MOV DX, note_dec
	CALL PUT_STR
	MOV DX, str_dec
	CALL PUT_STR		; num in dec form
	;
	CALL NEW_LINE
	;
	MOV DX, note_hex
	CALL PUT_STR
	MOV DX, str_hex
	CALL PUT_STR		; num in hex form
	;
	CALL NEW_LINE
	;
	
	MOV DX, note_exit
	CALL PUT_STR
	CALL GET_CHAR	;实现按任意键退出
    MOV   AH, 4CH
    INT   21H		;返回操作系统
;---------------------------------------
;
;子程序:GET_CHAR
;输入：等待键盘输入
;输出：AL-读取的字节（键盘输入）
;
GET_CHAR:
	MOV   AH, 1		;read a char
	INT   21H
	RET
;---------------------------------------
;
;子程序:GET_STR
;输入：DI-内存单元首地址
;输出：DI
;
GET_STR:
	CALL GET_CHAR
	CMP AL, 0DH		;detect Enter
	JE FIN_GET_STR
	
	MOV [DI], AL
	INC DI
	JMP GET_STR
FIN_GET_STR:
	; MOV DL, 0DH
	; MOV [DI], DL
	; INC DI
	; MOV DL, 0AH
	; MOV [DI], DL
	; INC DI
	MOV DL, '$'
	MOV [DI], DL
	RET
;----------------------------------------
;
;子程序:PUT_CHAR
;输入：DL-待显示的字节字符
;输出：控制台显示
;
PUT_CHAR:
	PUSH EAX
	MOV   AH, 2 	;put a char
	INT   21H
	POP EAX
	RET
;----------------------------------------
;
;子程序:PUT_STR
;输入：DS:DX-内存单元首地址
;输出：控制台显示
;注意：'$'结束字符串
;
PUT_STR:
	PUSH EAX
    MOV   AH, 9
    INT   21H           ;显示DS:DX开始的字符串（以$结尾）
	POP EAX
	RET
;----------------------------------------
;
;子程序:NEW_LINE
;输入：无
;输出：控制台显示换行
;
NEW_LINE:
	PUSH EAX
	MOV AH, 2		;\r\n
	MOV DL, 0DH
	INT 21H
	MOV DL, 0AH
	INT 21H
	POP EAX
	RET
;----------------------------------------
;
;子程序:CONVERT_STR_TO_INT
;输入：ESI-存放转换结果输出地址的通用寄存器
;输出：EAX-存放数值的通用寄存器
;
CONVERT_STR_TO_INT:
		PUSH EBX;	//用栈保护被调用者保存寄存器
		PUSH EDI;
		PUSH ECX;
		PUSH EDX;
		MOV ECX, 0;	//ECX为入栈个数计数器
		MOV BX, 10;
STR_LENGTH:
		MOV AL, [ESI+ECX];
		CMP AL, '$';
		JE STR_TO_INT;	//读到'$'，则跳出

		MOVZX AX, AL;
		PUSH AX;
		INC ECX;
		JMP STR_LENGTH;
STR_TO_INT:
		MOV EDX, 0;
		MOV EAX, 0;
		MOV EDI, 0;		//EDX作为临时求和寄存器，初始化置零
ADD_LOOP:
		CMP EDX, ECX;	//栈中数据全部取出，则加法循环结束并跳出至ADD_FIN
		JE ADD_FIN;
		POP AX;			//否则，POP取出数据
		SUB AX, '0';	//POP出的字符须转为十进制数值

		PUSH EDX;	//保存出栈序数EDX
	MUL_LOOP:
		CMP EDX, 0;		//设EDX为出栈序数，i号元素和10乘i次（i从0开始）
		JE MUL_FIN;
		PUSH EDX;
		MUL BX;			//AX与BX相乘，乘法运算结果在DX:AX中
		POP EDX;
		DEC EDX;

		JMP MUL_LOOP;
	MUL_FIN:
		POP EDX;	//还原出栈序数EDX
		INC EDX;
		MOVZX EAX, AX;
		ADD EDI, EAX;

		JMP ADD_LOOP;
ADD_FIN:
		MOV EAX, EDI;
		POP EDX
		POP ECX
		POP EDI;
		POP EBX;
		RET;
;----------------------------------------
;
;子程序:CONVERT_INT_TO_STR
;输入：EAX-存放数值的通用寄存器
;	   EDI-存放转换结果输出地址的通用寄存器
;输出：通用寄存器EDI所指向的字符数组的值
;
CONVERT_INT_TO_STR:
	PUSH EBX;
	MOV ECX, 0;		//ECX作为入栈个数计数器，初始化置零
	MOV BX, 10;
		
tDIV_PUSH:
	MOVZX EAX, AX;
	ROL EAX, 16;	//左循环移16位，使高16位位于AX
	MOV DX, AX;		//高16位从AX移入DX
	ROR EAX, 16;	//恢复

	DIV BX;			//商：AX，余数：DX
	PUSH DX;
	INC ECX;
	
	CMP AX, 0;		//商为0，则不再除，跳出除运算循环
	JE tPRE_POP;
	JMP tDIV_PUSH;
tPRE_POP:
	MOV EBX, 0;		//EBX作为出栈个数计数器，初始化置零
tPOP_LOOP:
	POP DX;			//取出两字节数据
	ADD DL, '0';	//数值转字符
	MOV [EDI+EBX], DL;	//将有效的低字节部分移入主存中的输出数组
	INC EBX;		//计数器加1
	
	CMP EBX, ECX;
	JE tPOP_END;
	JMP tPOP_LOOP;
tPOP_END:
	MOV DL, '$'
	MOV [EDI+EBX], DL;	//字符数组结尾须补'$'
	POP EBX;
	RET;
;----------------------------------------
;
;子程序:CONVERT_INT_TO_HEX
;输入：EAX-存放数值的通用寄存器
;输出：EDI-存放转换结果输出地址的通用寄存器
;
CONVERT_INT_TO_HEX:
		MOV ECX, 0;		//ECX作为入栈个数计数器，初始化置零
		MOV BX, 16;
		
DIV_PUSH:
		MOVZX EAX, AX;
		ROL EAX, 16;	//左循环移16位，使高16位位于AX
		MOV DX, AX;		//高16位从AX移入DX
		ROR EAX, 16;	//恢复

		DIV BX;			//商：AX，余数：DX
		PUSH DX;
		INC ECX;
		
		CMP AX, 0;		//商为0，则不再除，跳出除运算循环
		JE PRE_POP;
		JMP DIV_PUSH;
PRE_POP:
		MOV EBX, 0;		//EBX作为出栈个数计数器，初始化置零
POP_LOOP:
		POP DX;			//取出两字节数据
		CMP DL, 9;
		JA ALPHA;
		JNA NUM;
NUM:	;DL<=9
		ADD DL, '0';	//数值转字符
		JMP WRITE_MEM;
ALPHA:	;10<=DL
		ADD DL, 55;		//'A'=65，DL = DL + ('A'-10)
		JMP WRITE_MEM;
WRITE_MEM:
		MOV [EDI+EBX], DL;	//将有效的低字节部分移入主存中的输出数组
		INC EBX;		//计数器加1
		
		CMP EBX, ECX;
		JE POP_END;
		JMP POP_LOOP;
POP_END:
		MOV DL, '$'
		MOV [EDI+EBX], DL;	//字符数组结尾须补'$'
		RET;
;----------------------------------------
;
note db "EX62_1427405017_JiayunShen",0DH,0AH,"Please Enter a Dec string:",0DH,0AH,'$'     ;定义字符串信息-初始化信息
note_str_in db "Memery str_in:",0DH,0AH,'$'     ;定义字符串信息-提示存储单元内容
note_dec db "Num in Dec form:",0DH,0AH,'$'	;定义字符串信息-提示十进制显示
note_hex db "Num in Hex form:",0DH,0AH,'$'	;定义字符串信息-提示十六进制显示
note_exit db "Press any key to exit.",0DH,0AH,'$'	;定义字符串信息-提示按任意键退出

str_in resb 100		; 预留100字节输入字符串空间
num_dec resd 1	;预留1双字空间存储整型数值
str_dec resb 100	; 预留100字节输出字符串空间，存储十进制字符
str_hex resb 100	; 预留100字节输出字符串空间，存储十六进制字符