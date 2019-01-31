int n ; 
cin >> n ; 

vector<int> Array(n);
for(size_t i=0; i<n ; i++)
  cin >> Array[i];

for(size_t i=0 ; i<n ; i++){
  for(size_t j=i ; j<n ; j++){
    for(size_t k=i ; k<=j ; k++)
      cout << Array[k] << " " ;
  }
}
