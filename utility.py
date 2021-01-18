def utility(state, x, y, pcTurn):
  
  patternComputer = [ "XXXXX", "-XXXX-", "XXXX-", "XX-XX", "XXX-X", "X-XXX-", "-XXX-", "XXX--", "-XX-X",
			"XX-X-", "-XX-X-", "--XX-", "XX---", "X---X", "X----", "--X--", "-X---" ];
  
  patternMan = [ "OOOOO", "-OOOO-", "OOOO-", "OO-OO", "OOO-O", "O-OOO-", "-OOO-", "OOO--", "-OO-O",
			"OO-O-", "-OO-O-", "--OO-", "OO---", "O---O", "O----", "--O--", "-O---" ];
  

  profit = [ 200000000, 50000, 15000, 420, 420, 480, 350, 300, 100, 100, 100, 50 / 15, 50 / 15, 50 / 15,
			20 / 10, 20 / 10, 20 / 10 ];

  if pcTurn:
    #state[x][y] = 'X'
    mult = 1 #pcTurn * 1 + (1-pcTurn) * -1
    pcProfit = []
    #diagonal right left
    for iter in range(5):
      pr = x + iter //r for right diagonal
      qr = y - iter //l for left diagonal
      pl = x + iter
      ql = y + iter
      sr = ''
      sl = ''

      for iterr in range(5):
        if !(pr<0 or pr >9 or qr<0 or qr>9):          
          sr += state[pr][qr]
          pr -= 1
          qr += 1
        
        if !(pl < 0 or pl > 9 or ql < 0 or ql > 9):          
          sl += state[pl][ql]
          pl -= 1
          ql -= 1
      
      if sr in patternMan:
        indx = patternMan.index(sr)
        pcProfit += [mult * profit[indx]]
      
      if sr[::-1] in patternMan:
        indx = patternMan.index(sr[::-1])
        pcProfit += [mult * profit[indx]]
      
      else:
        sr2 = sr[:iter] + 'X' + sr[iter+1:]
        
        if sr2 in patternComputer:
          indx = patternComputer.index(sr2)
          pcProfit += [mult * profit[indx]]
        
        elif sr2[::-1] in patternComputer:
          indx = patternComputer.index(sr2[::-1])
          pcProfit += [mult * profit[indx]]

      if sl in patternMan:
        indx = patternMan.index(sl)
        pcProfit += [mult * profit[indx]]
      
      elif sl[::-1] in patternMan:
        indx = patternMan.index(sl[::-1])
        pcProfit += [mult * profit[indx]]

      else:
        sl2 = sl[:iter] + 'X' + sl[iter+1:]
        
        if sl2 in patternComputer:
          indx = patternComputer.index(sl2)
          pcProfit += [mult * profit[indx]]
        
        elif sl2[::-1] in patternComputer:
          indx = patternComputer.index(sl2[::-1])
          pcProfit += [mult * profit[indx]]

    #up down left right
    for iter in range(5):
      pu = x + iter
      qu = y
      ph = x
      qh = y - 1
      #q = y + iter
      su = ''
      sh = ''

      for iterr in range(5):
        if !(pu < 0 or pu > 9 or qu < 0 or qu > 9):
          su += state[pu][qu]
          pu -= 1
        
        if !(ph < 0 or ph > 9 or qh < 0 or qh > 9):
          sh += state[ph][qh]
          qh -= 1
      
      if su in patternMan:
        indx = patternMan.index(su)
        pcProfit += [mult * profit[indx]]
      
      elif su[::-1] in patternMan:
        indx = patternMan.index(su[::-1])
        pcProfit += [mult * profit[indx]]

      else:
        su2 = su[:iter] + 'X' + su[iter+1:]
        
        if su2 in patternComputer:
          indx = patternComputer.index(su2)
          pcProfit += [mult * profit[indx]]
        
        if su2[::-1] in patternComputer:
          indx = patternComputer.index(su2[::-1])
          pcProfit += [mult * profit[indx]]

      if sh in patternMan:
        indx = patternMan.index(sh)
        pcProfit += [mult * profit[indx]]

      elif sh[::-1] in patternMan:
        indx = patternMan.index(sh[::-1])
        pcProfit += [mult * profit[indx]]
      
      else:
        sh2 = sh[:iter] + 'X' + sh[iter+1:]
        
        if sh2 in patternComputer:
          indx = patternComputer.index(sh2)
          pcProfit += [mult * profit[indx]]

        elif sh2[::-1] in patternComputer:
          indx = patternComputer.index(sh2[::-1])
          pcProfit += [mult * profit[indx]]
    
    return pcProfit


    else:
      
      #state[x][y] = 'X'
      mult = -1 #pcTurn * 1 + (1-pcTurn) * -1
      manProfit = []
      #diagonal right left
      for iter in range(5):
        pr = x + iter //r for right diagonal
        qr = y - iter //l for left diagonal
        pl = x + iter
        ql = y + iter
        sr = ''
        sl = ''

        for iterr in range(5):
          if !(pr<0 or pr >9 or qr<0 or qr>9):          
            sr += state[pr][qr]
            pr -= 1
            qr += 1
          
          if !(pl < 0 or pl > 9 or ql < 0 or ql > 9):          
            sl += state[pl][ql]
            pl -= 1
            ql -= 1
        
        if sr in patternComputer:
          indx = patternComputer.index(sr)
          manProfit += [mult * profit[indx]]
        
        if sr[::-1] in patternComputer:
          indx = patternComputer.index(sr[::-1])
          manProfit += [mult * profit[indx]]
        
        else:
          sr2 = sr[:iter] + 'O' + sr[iter+1:]
          
          if sr2 in patternMan:
            indx = patternMan.index(sr2)
            manProfit += [mult * profit[indx]]
          
          elif sr2[::-1] in patternMan:
            indx = patternMan.index(sr2[::-1])
            manProfit += [mult * profit[indx]]

        if sl in patternComputer:
          indx = patternComputer.index(sl)
          manProfit += [mult * profit[indx]]
        
        elif sl[::-1] in patternComputer:
          indx = patternComputer.index(sl[::-1])
          manProfit += [mult * profit[indx]]

        else:
          sl2 = sl[:iter] + 'O' + sl[iter+1:]
          
          if sl2 in patternMan:
            indx = patternMan.index(sl2)
            manProfit += [mult * profit[indx]]
          
          elif sl2[::-1] in patternMan:
            indx = patternMan.index(sl2[::-1])
            manProfit += [mult * profit[indx]]

      #up down left right
      for iter in range(5):
        pu = x + iter
        qu = y
        ph = x
        qh = y - 1
        #q = y + iter
        su = ''
        sh = ''

        for iterr in range(5):
          if !(pu < 0 or pu > 9 or qu < 0 or qu > 9):
            su += state[pu][qu]
            pu -= 1
          
          if !(ph < 0 or ph > 9 or qh < 0 or qh > 9):
            sh += state[ph][qh]
            qh -= 1
        
        if su in patternComputer:
          indx = patternComputer.index(su)
          manProfit += [mult * profit[indx]]
        
        elif su[::-1] in patternComputer:
          indx = patternComputer.index(su[::-1])
          manProfit += [mult * profit[indx]]

        else:
          su2 = su[:iter] + 'O' + su[iter+1:]
          
          if su2 in patternMan:
            indx = patternMan.index(su2)
            manProfit += [mult * profit[indx]]
          
          if su2[::-1] in patternMan:
            indx = patternMan.index(su2[::-1])
            manProfit += [mult * profit[indx]]

        if sh in patternComputer:
          indx = patternComputer.index(sh)
          manProfit += [mult * profit[indx]]

        elif sh[::-1] in patternComputer:
          indx = patternComputer.index(sh[::-1])
          manProfit += [mult * profit[indx]]
        
        else:
          sh2 = sh[:iter] + 'O' + sh[iter+1:]
          
          if sh2 in patternMan:
            indx = patternMan.index(sh2)
            manProfit += [mult * profit[indx]]

          elif sh2[::-1] in patternMan:
            indx = patternMan.index(sh2[::-1])
            manProfit += [mult * profit[indx]]
      
      return manProfit
