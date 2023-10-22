#include <iostream>
#include <cryptopp/base64.h>
#include <string>
#include <cryptopp/aes.h>
#include <cryptopp/modes.h>
#include <cstdlib>

using namespace std;
using namespace CryptoPP;
using CryptoByte = CryptoPP::byte;

// aa is using on commend line input ./exe (aa) 
int aa = 0;

// Implementation of zero-padding
string zeroPadKey(const string& key, const size_t desiredLength) 
{
    string paddedKey = key;
    while (paddedKey.length() < desiredLength) 
	{
        paddedKey.push_back('\0');  // Add null characters for zero-padding
    }
    return paddedKey;
}

// I think that has some problem or bug, but I can find it.
// The lastest step to decrypt, to determine whether it contain illegal char. 
bool isOnlyAllowedChar(const std::string str, const std::string& allowedCharacters) 
{
	//cout << "in isOnly" << endl;
    for (char c : str) 
    {
        /*if (allowedCharacters.find(c) == string::npos) 
	{
	    cout << str << " no find: " << c <<endl;
            return false;
        }*/
	if ((int)c==32 || (int)c==33 || (int)c==39 || (int)c==46 || (int)c==63 || (int)c==44)
	{
		//cout << str << " 1. no find: " << c <<endl;
		return true;
	}else if (((int)c>64&&((int)c<91)))
	{
		//cout << str << " 2. no find: " << c <<endl;
		return true;
	}else if (((int)c>96&&((int)c<123)))
        {
		//cout << str << " 3. no find: " << c <<endl;
                return true;
        }else if (((int)c>47&&((int)c<58)))
	{
		return true;
    	}else
	{
		return false;
	}
    }
cout << "end isOnly" << endl;
return true;
    // Iterate over the first n characters
   /* for (size_t i = 0; str[i] != '\0'< std::min(str.length(), static_cast<size_t>(5)); ++i) {
        //cout << "for" << endl;
	char c = str[i];
	//cout << "string length: " << str.length() << " string data: " << str << endl;
        //cout << "i=" << i <<endl;
	if (allowedCharacters.find(c) == std::string::npos) {
            //cout << "a"<<endl;
		return false;  // allow cannt allow char
        }
    }
    cout << "end isOnly" << endl;
    return true;  // string first n char only allow char
   */ 
}

// some constant
string ALLOWEDCHAR = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789 ,.?!'";
string ALPHABET = " !\"#$%&\'()*+,-./0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ[\\]^_`abcdefghijklmnopqrstuvwxyz{|}~";
string testALPHABET = "123456789";


int main(int argc, char *argv[])
{
	// group 0~4
	int X;
	X = -1;

	// testing commend line input
	aa = atoi(argv[1]);

	// test only
	string key;
	// useful
	string cipher,utf8Cipher,plainText,key1,key2,key3,key4,key5,keyStr="";
	Base64Decoder decoder;
	ECB_Mode< AES >:: Decryption AESDecipher;
	SecByteBlock AESKey;
	const size_t desiredKeyLength = 16;
	StreamTransformationFilter* decryptorFilter = nullptr; 
	
	// group
	switch (X)
	{
	case -1:
		// Initialzation settings
		// key = "123456789";
		key1 = "12";
		key2 = "45";
		key3 = "78";
		key4 = "";
		key5 = "";
		// key = zeroPadKey(key, desiredKeyLength);

		cipher = "pKjVPv28yVMn5cRXeUNYpg==";
		// cout << "original data ciphertext: " << cipher << endl;

		/* AESKey.Assign((CryptoByte*)key.data(),AES::DEFAULT_KEYLENGTH);
		// base64 to uft-8
		decoder.Put((CryptoByte*)cipher.data(),cipher.size());
		decoder.MessageEnd();
		utf8Cipher.resize(decoder.MaxRetrievable());
		decoder.Get((CryptoByte*)(&utf8Cipher[0]),utf8Cipher.size());

		cout << "uft8 Text : " << utf8Cipher << endl;
		
		cout << "key: " << key << " sizeof key " << key.size() << endl;
		//AES Decryption
		AESDecipher.SetKey(AESKey,AESKey.size());
		cout << "AESKey.size() " << AESKey.size() << endl;
		
		// Decryption Opration
		decryptorFilter = new StreamTransformationFilter(AESDecipher, new StringSink(plainText),StreamTransformationFilter::ZEROS_PADDING);
    	decryptorFilter->Put((CryptoByte*)(utf8Cipher.data()), utf8Cipher.size());
    	decryptorFilter->MessageEnd();

    	cout << "Decrypted text: " << plainText << std::endl;
		*/
		break;
	case 0:
		cipher = "2NHkjlDyk82JBke5q8CnMQZ1iiHID8QEst+/Ld6lWFMP5omXXh/1LnmrYKOD04idKfzfL+6C96391/iN7+X0eg==";
		key1="$\"";
		key2="vXl";
		key3="K";
		key4="\\/{9Fp";
		key5="";
		break;
	case 1:
		cipher = "INNkAZHIpe5u9LvzhH24VyORcZQVDCFXzV6V/l9M7rpgqskMxvaRbGwR2dZaxMDZ";
		key1="0lOS";
		key2="b]";
		key3="&N)";
		key4="w";
		key5="@+";
		break;
	case 2:
		cipher = "NnJyrVT80DxOU5jOxHdZ9NRlaLPRhaAUYANfaVACUeqcrPoXz5eeTs9m6X2fVJC9SJ+X03mu3zD/WTiUjwzIyg==";
		key1="Bk";
		key2="fom]";
		key3="H";
		key4="(J";
		key5="'|,";
		break;
	case 3:
		cipher = "89NEvN56VtNjo1w5x3whmFUOZOqTaRyoMnIrPjCGKUv5n7kgGFHDmStzEgDFAU7QnZOK9MLeO/FW4etzIOhpKfOsw5xSD4Em72X1O2FRfaM=";
		key1="2";
		key2="?";
		key3="mYD;@";
		key4=";x";
		key5="v\"i";
		break;
	case 4:
		cipher = "FZp57a6p84EUNC7I/ENj4RhPZtryOJr4che9JbA8ng1eI8ZMTlsl8kzicBDqkOqkFj3lwC69KR2MeA8lscVlig==";
		key1="|q";
		key2="~k=";
		key3="&?I$Fx";
		key4="N";
		key5="";
		break;
	default:
		cout << "cipher error or studentID  error" << endl;
		break;
	}
	cout << "original data ciphertext: " << cipher << endl;

	// base64 to uft-8
	decoder.Put((CryptoByte*)cipher.data(),cipher.size());
	decoder.MessageEnd();
	utf8Cipher.resize(decoder.MaxRetrievable());
	decoder.Get((CryptoByte*)(&utf8Cipher[0]),utf8Cipher.size());

	cout << "uft8 Text : " << utf8Cipher << endl;
	
	// cout << "key: " << key << " sizeof key " << key.size() << endl;
/*	for(int a = aa; a < (aa+2) && a < ALPHABET.length(); a++)
	{
		cout << "a: " << a <<endl;
		for(int b = 0; b < ALPHABET.length(); b++)
		{
			for(int c = 0; c < ALPHABET.length(); c++)
			{
				for(int d = 0; d < ALPHABET.length(); d++)
				{
					// connect key
					keyStr = key1;
					keyStr += ALPHABET[a];
					keyStr.append(key2);
					keyStr += ALPHABET[b];
					keyStr.append(key3);
					keyStr += ALPHABET[c];
					keyStr.append(key4);
					keyStr += ALPHABET[d];
					keyStr.append(key5);
					
					//cout<< "keyStr: " << keyStr << endl;

					AESKey.Assign((CryptoByte*)keyStr.data(),AES::DEFAULT_KEYLENGTH);
					//AES Decryption
					AESDecipher.SetKey(AESKey,AESKey.size());
					// cout << " AESKey.size() " << AESKey.size() << endl;
		
					// Decryption Opration
					plainText.clear();
					decryptorFilter = new StreamTransformationFilter(AESDecipher, new StringSink(plainText),StreamTransformationFilter::ZEROS_PADDING);
   					decryptorFilter->Put((CryptoByte*)(utf8Cipher.data()), utf8Cipher.size());
   					decryptorFilter->MessageEnd();

					if(isOnlyAllowedChar(plainText,ALLOWEDCHAR))
					{
						cout << "Decrypted text: " << plainText << std::endl;
						delete decryptorFilter;
						// return 0;
					}
  				 	
				}			
			}
		}
	}
*/




	// testing code
	
	keyStr = key1;
	keyStr += testALPHABET[2];
	keyStr.append(key2);
	keyStr += testALPHABET[5];
	keyStr.append(key3);
	keyStr += testALPHABET[8];
	keyStr.append(key4);
	keyStr.append(key5);
	cout<< "off for  keyStr: " << keyStr << endl;
	AESKey.Assign((CryptoByte*)keyStr.data(),AES::DEFAULT_KEYLENGTH);
     	//AES Decryption
    	AESDecipher.SetKey(AESKey,AESKey.size());
    	// cout << " AESKey.size() " << AESKey.size() << endl;
    	// Decryption Opration
    	decryptorFilter = new StreamTransformationFilter(AESDecipher, new StringSink(plainText),StreamTransformationFilter::ZEROS_PADDING);
    	decryptorFilter->Put((CryptoByte*)(utf8Cipher.data()), utf8Cipher.size());
	decryptorFilter->MessageEnd();
	cout << "Decrypted text: " << plainText << std::endl;

                    if(isOnlyAllowedChar(plainText,ALLOWEDCHAR))
                    {
                        cout << "Only allow Decrypted text: " << plainText << std::endl;
                        delete decryptorFilter;
                        // return 0;
        	    }
		    
	cout << "------------------------------------------------------------------------" << endl;
	
	for(int a = aa; a<aa+2 && a < testALPHABET.length(); a++)
        {
                cout << "a: " << a <<endl;
                for(int b = 0; b < testALPHABET.length(); b++)
                {
                        for(int c = 0; c < testALPHABET.length(); c++)
                        {
                                // for(int d = 0; d < ALPHABET.length(); d++)
                                
                                        // connect key
                                        keyStr = key1;
                                        keyStr += testALPHABET[a];
                                        keyStr.append(key2);
                                        keyStr += testALPHABET[b];
                                        keyStr.append(key3);
                                        keyStr += testALPHABET[c];
                                        keyStr.append(key4);
                                        // keyStr += ALPHABET[d];
                                        keyStr.append(key5);

                                        //cout<< "keyStr: " << keyStr << endl;

                                        AESKey.Assign((CryptoByte*)keyStr.data(),AES::DEFAULT_KEYLENGTH);
                                        //AES Decryption
                                        AESDecipher.SetKey(AESKey,AESKey.size());
                                        // cout << " AESKey.size() " << AESKey.size() << endl;

                                        // Decryption Opration
                                        plainText.clear();
					decryptorFilter = new StreamTransformationFilter(AESDecipher, new StringSink(plainText),StreamTransformationFilter::ZEROS_PADDING);
                                        decryptorFilter->Put((CryptoByte*)(utf8Cipher.data()), utf8Cipher.size());
                                        decryptorFilter->MessageEnd();

                                        //cout << /*" error test: " << plainText <<*/ std::endl; 
					if(isOnlyAllowedChar(plainText,ALLOWEDCHAR))
                                        {
						cout << "\n********************************\n" << "Decrypted text: " << plainText << std::endl;
						cout << "\n********************************" << endl;
                                                delete decryptorFilter;
                                               // return 0;
                                        }

                                
                        }
                }
        }
	
	//delete decryptorFilter;
	return 0;
}
