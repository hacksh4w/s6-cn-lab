### ALGORITHM : 
 Start
2. Initialize variables:  bucket_size, outgoing, n, incoming, store = 0 as integers.
3. Read and store the bucket size (bucket_size) from the user.
4. Read and store the number of inputs (n) from the user.
5. Read and store the packet outgoing rate (outgoing) from the user.
6. While n is not equal to 0:
  6.1 Read, store and display the incoming packet size (incoming) from the user.
  6.2 If incoming is less than or equal to the available space in the bucket (bucket_size - store), then:
    - Add the incoming packet size (incoming) to the bucket (store += incoming).
  Display "Bucket Buffer Size store out of bucket_size"
  If in is greater than the available space in the bucket (bucket_size - store), then:
  Calculate the number of dropped packets (incoming - (bucket_size - bucket)).
        - Display "Dropped x no: of packets."
        - Display "Bucket Buffer Size x out of y"
  Set the bucket size (bucket) to its maximum capacity (bucket_size).
  Print the number of dropped packets. 
6.3.  Print the bucket status (bucket packets out of bucket_size).
6.4.  Subtract the packet outgoing rate (outgoing) from the bucket size (store).
6.5.  Print the bucket status after outgoing packets (bucket packets out of bucket_size).
6.6.  Decrement the value of n by 1.
End While Loop.
End.
