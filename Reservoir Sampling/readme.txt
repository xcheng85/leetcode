Reservoir Sampling
goal:So we are given a big array (or stream) of numbers (to simplify), 
and we need to write an efficient function to randomly select k numbers where 1 <= k <= n. Let the input array be stream[].

ReservoirSample(S[1..n], R[1..k])
  // fill the reservoir array
  for i = 1 to k
      R[i] := S[i]

  // replace elements with gradually decreasing probability
  for i = k+1 to n
    j := random(1, i)   // important: inclusive range
    if j <= k
        R[j] := S[i]