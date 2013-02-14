Example demonstrating use of the lateAcquire API implemented for the Ducati M3
part. Algorithm acquires a handle to the IRES HDVICP2 resource, and then calls
the lateAcquire API on it, during its process call.
Before this call, it would yield to higher priority process of the
same/different scratch group. 
