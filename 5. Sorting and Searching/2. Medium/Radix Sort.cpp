//User function Template for C++

void countSort(int arr[], int n, int exponent){
    vector<int> count(10,0);
    vector<int> output(n,0);
    
    // Step 1: Count the occurrences of each digit at the current exponent place.
    for(int i = 0; i < n; i++)
        count[(arr[i]/exponent)%10]++;
    
    // Step 2: Modify the count array to hold the correct positions of each digit in the sorted output.
    for(int i = 1; i < 10; i++)
        count[i] += count[i-1];
        
    // Step 3: Build the output array based on the positions obtained from the count array.
    for(int i = n-1; i >= 0; i--){
        output[count[(arr[i]/exponent)%10] -1] = arr[i];
        count[(arr[i]/exponent)%10]--;
    }
    
    // Step 4: Update the original array with the sorted output.
    for(int i = 0; i < n ; i++)
        arr[i] = output[i];
}

void radixSort(int arr[], int n) 
{ 
   // Find the maximum element to determine the number of digits in the maximum element.
   int maxElement = *max_element(arr, arr+n);
   
   // Perform counting sort for each digit place from least significant to most significant.
   for(int exponent = 1; maxElement/exponent > 0; exponent *= 10)
        countSort(arr,n,exponent);
}