##Binary to Hex Script
import os 
import sys
import binascii


global byte_array
global init_byte
global hex_list

def main():
	dir_path = os.getcwd()
	file_name = sys.argv[1]
	full_path = dir_path + "/" + file_name
	file = open(full_path, "r");
	content = file.read();
	content = content.split()
	content = ''.join(content)
	len_block = len(content)
	num_bytes = len_block/8

	print(content)
	i = 0
	j = 0
	byte_array = []
	init_byte = []
	for bit in content:
		i = i + 1
		init_byte.append(bit)
		if i == 8:
			#print(init_byte)
			byte_array.append(init_byte)
			i = 0
			j = j + 1
			init_byte = []
		#4 bits at a time, convert those four bits to hex representation.
		#for i in range(0,7):

	#print(byte_array)

	hex_list = []
	for byte in byte_array:
		byte = ''.join(byte)
		#print(byte)
		int_rep = int(byte, 2)
		hex_rep = '%02X' % int_rep
		hex_list.append(hex_rep)

	#print(hex_list)
	hex_string = ''.join(hex_list)
	hex_list = hex_string.split('x')
	hex_string = ''.join(hex_list)
	print(hex_string)


# display some lines

if __name__ == "__main__": main()