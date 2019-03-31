##	THUẬT TOÁN MÃ HÓA LZW (Lempel–Ziv–Welch)

	1. LZW là 1 phương pháp nén dữ liệu ĐPT.
	2. LZW là kỹ thuật nén Lossless.
	3. Sử dụng nén tệp tin : .txt , .docx, … 
	4. Thường sử dụng để nén GIF và tùy chọn trong PDF và TIFF.

##	NGUYÊN TẮC HOẠT ĐỘNG 
	1. Nén LZW hoạt động bằng cách đọc một chuỗi các ký hiệu,nhóm các ký hiệu thành chuỗi và chuyển đổi chuỗi thành mã. 
	2. Một xâu ký tự là một tập hợp từ hai ký tự trở lên. 
	3. Nhớ tất cả các xâu ký tự đã gặp và gán cho nó một dấu  hiệu (token) riêng.
	4. Nếu lần sau gặp lại xâu ký tự đó, xâu ký tự sẽ được thay thế bằng dấu hiệu đã được mã hóa.

##	THUẬT TOÁN NÉN FILE LZW
# MÃ GIẢI :
	1. Initialize table with single character strings.
	2. P = first input character.
	3. While not end of input  stream.
	4.     C = next input character
	5. 	   If P + C is in the string table.
	6.		P = P + C
	7.	   ELSE
    8.	   		Output the code for P
    9.			Add P + C to the string table.
	10.			P = C.
	11. End While.
	12. Output code for P

##	THUẬT TOÁN GIẢI NÉN FILE LZW
# MÃ GIẢI :
	1. Initialize table with single              character strings.
	2. OLD = first input code.
	3. Output translation of OLD
	4. While not end of input  stream.
	5.     New = next input code.
	6.     If New is not in string table.
    	7.	   	S = translation of OLD.
    	8. 	   	C = first character of S.
	9.	   	S = S + C.
	10.    Else
	11.		S = translation of New.
	12.    Output S.
	13.    C = first character of S.
	14.    OLD + C to the string table.
	15.    OLD = New.
	16. End While.

## TRỢ GIÚP
Nếu bạn có thắc mắc hãy liên hệ với tôi qua [Github](https://github.com/DoManhQuang) hoặc là [Facebook](https://www.facebook.com/ManhQuangITBlue)








