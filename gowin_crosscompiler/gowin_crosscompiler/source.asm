nop
nop
LDH(reg0, 0);
nop
nop
LDL(reg0, 1); reg0 = カウンタ
nop
nop
LDH(1, 0);
nop
nop
LDL(1, 0); reg1 = 合計値
nop
nop
LDH(2, 0);
nop
nop
LDL(2, 1); reg2 = 1（固定値）
nop
nop
LD (3, 8); reg3 = SWの値
nop
nop
mov(4,3);  reg4に最初のSWの値を格納。
LDH(5, 0);
LDL(5, 0); reg5 = 0（固定値）
nop
nop
cmp(5, 3); reg5とreg3を比較。
je (45);  イコールだったらジャンプ。
add(1,0);  reg1にカウンタ値を足す。
cmp(0, 3); reg0とreg3を比較。
je (38);  イコールだったらジャンプ。
add(0,2);
nop
nop
add(1,0);
jmp(31);
st (1,64); reg1を7segに出力。
LD (3, 8);
nop
nop
cmp(3, 4); reg4とreg3を比較。
je (38);  イコールだったらジャンプ。
jmp(0); 入力値に変化があったので、初めから再スタート。
st (1,64); reg1を7segに出力。
jmp(0); 入力値に変化があったので、初めから再スタート。