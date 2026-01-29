int pivotStringIndex(char* s) {
    int n = strlen(s);
    int i;

//if (n % 2 == 0) return -1

    
    for (i = 0; i < n; i++) {
       
      
        int comp_esq = i;
        int comp_dir = n - i - 1;
        if (comp_esq != comp_dir) {
         
            continue;
        }
       
        int j;
        int igual = 1;
        for (j = 0; j < comp_esq; j++) {
            if (s[j] != s[i+1+j]) {
                igual = 0;
                break;
            }
        }
        if (igual) {
            return i;
        }
    }
    return -1;
}
