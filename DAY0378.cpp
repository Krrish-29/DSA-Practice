// 2075. Decode the Slanted Ciphertext
class Solution {
public:
    string decodeCiphertext(string encodedText, int rows) {
        int size=encodedText.size();
        int m=rows,n=size/m;
        string cipher;
        // making cipher string
        // for(int col=0;col<n;col++){
        //     int i=0,j=col;
        //     while(i<m&&j<n){
        //         cipher+=encodedText[i*n+j];
        //         i++;
        //         j++;
        //     }
        // }

        // using grid for simulation
        vector<vector<char>>matrix(m,vector<char>(n));
        int idx=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                matrix[i][j]=encodedText[idx];
                idx++;
            }
        }
        for(int col=0;col<n;col++){
            int i=0,j=col;
            while(i<m&&j<n){
                cipher+=matrix[i][j];
                i++;
                j++;
            }
        }

        for(int i=cipher.size()-1;i>=0;i--){
            if(cipher[i]==' ') {
                cipher.erase(cipher.begin()+i);
            }
            else break;
        }
        return cipher;
    }
};