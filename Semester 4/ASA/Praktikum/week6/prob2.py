from decimal import Decimal, InvalidOperation, getcontext
getcontext().prec = 50

n = int(input())
for _ in range(n):
    s = input().strip()
    sl = s.lower()
    
    if sl == 'nan':
        print('NaN')
    elif sl in ('inf', '+inf'):
        print('inf')
    elif sl == '-inf':
        print('-inf')
    elif float(s) == 0:
        print('inf')  # atau -inf tergantung sign
    else:
        try:
            d = Decimal(s)
            result = Decimal(1) / d
            print(result)
        except InvalidOperation:
            print('NaN')