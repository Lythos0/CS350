def is_prime(n)
    i = 2
    while i * i <= n
      if n % i == 0
    return false
      end
    i += 1
    end
    true
  end
  
  primes = []
  i = 2
  while i <= 100
    if is_prime(i)
      primes << i
    end
    i += 1
  end
  i = 0
  while i < primes.length
    puts primes[i]
i += 1
  end
  