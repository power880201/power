function [Data,Time] = BinFinder1(ID_num,Factor,Offset,start,endbit,ID,Min,Sec,Sec_4,byte0,byte1,byte2,byte3,byte4,byte5,byte6,byte7)
ID_numCount=0; %%該ID量測到幾次的計數器
Factor_Offset=[Factor Offset];

%     BigEndianTable = [63 62	61	60	59	58	57	56
%             55	54	53	52	51	50	49	48
%             47	46	45	44	43	42	41	40
%             39	38	37	36	35	34	33	32
%             31	30	29	28	27	26	25	24
%             23	22	21	20	19	18	17	16
%             15	14	13	12	11	10	9	8
%             7	6	5	4	3	2	1	0];
%     EndBit = StartBit+SigSize-1;
%     Byte_Ie = floor(StartBit/8);
%     Byte_Is = floor(EndBit/8);
%     
%     [Isx,Isy] = find((StartBit)==BigEndianTable);  
%     [Iex,Iey] = find((EndBit)==BigEndianTable); 
    
    
    
    
for i=1:length(ID)   % 提取時間以及該數據對應的byte
    if ID(i)==ID_num
        ID_numCount=ID_numCount+1;
        Time(ID_numCount,1)=(Min(i)*60*10000+Sec(i)*10000+Sec_4(i))/10000;%%取出時間
        Data_extract(ID_numCount,1)=byte7(i);
        Data_extract(ID_numCount,2)=byte6(i);
        
        Data_extract(ID_numCount,1:8)=[byte0(i) byte1(i) byte2(i) byte3(i) byte4(i) byte5(i) byte6(i) byte7(i)];
        
    end
end

for j=1:length(Data_extract) %%十進轉二進再合併再轉十進
    
    AA0=num2str(str2num(dec2bin(Vx_kps_data1(j,1))),'%08d'); % byte0
    AA1=num2str(str2num(dec2bin(Vx_kps_data1(j,2))),'%08d'); % byte1
    AA2=num2str(str2num(dec2bin(Vx_kps_data1(j,3))),'%08d'); % byte2
    AA3=num2str(str2num(dec2bin(Vx_kps_data1(j,4))),'%08d'); % byte3
    AA4=num2str(str2num(dec2bin(Vx_kps_data1(j,5))),'%08d'); % byte4
    AA5=num2str(str2num(dec2bin(Vx_kps_data1(j,6))),'%08d'); % byte5
    AA6=num2str(str2num(dec2bin(Vx_kps_data1(j,7))),'%08d'); % byte6
    AA7=num2str(str2num(dec2bin(Vx_kps_data1(j,8))),'%08d'); % byte7
    AA=[AA0 AA1 AA2 AA3 AA4 AA5 AA6 AA7]; % [byte0 byte1 byte2 byte3 byte4 byte5 byte6 byte7]
    
    Data(j)=bin2dec(AA(start:endbit))*Factor_Offset(1)+Factor_Offset(2);
    
end