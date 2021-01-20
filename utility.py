def utility(gameState, x, y):

  #-XXXX- 2 50000  X-XXX- 6 480 "-XX-X-" 11 100
  patternComputer = [ "XXXXX", "XXXX-", "XX-XX", "XXX-X", "-XXX-", "XXX--", "-XX-X", #7
			"XX-X-", "--XX-", '-XX--', "XX---", 'XX--X', 'X-X--', "X---X",  'X--X-', '-X-X-', 'X-X-X', "--X--", "-X---", "X----" ]; #14
  
  patternMan = [ "OOOOO", "OOOO-", "OO-OO", "OOO-O", "-OOO-", "OOO--", "-OO-O", #7
			"OO-OO-", "--OO-", '-OO--', "OO---", 'OO--O', 'O-O--', "O---O",  'O--O-', '-O-O-', 'O-O-O', "--O--", "-O---", "O----" ];
  
  
  profit = [ 200000000, 50000, 15000, 15000, 480, 420, 350, 350, 200, 150, 50, 20, 10, 10, 10, 10, 10, 5, 5, 1 ]
  #sum = 200082081
  state = [[]]
  for i in range(10):
    for j in range(10):
      if gameState[i][j] == 1:
        state[i].append('X')
      elif gameState[i][j] == -1:
        state[i].append('O')
      else:
        state[i].append('-')


  if state[x][y]== 'X':
    
    state[x][y] = '-'
    mult = 1 #pcTurn * 1 + (1-pcTurn) * -1
    pcProfit = 0
    #diagonal right left
    for iter in range(5):
      pr = x + iter #r for right diagonal
      qr = y - iter #l for left diagonal
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
        pcProfit += mult * profit[indx]
      
      elif sr[::-1] in patternMan:
        indx = patternMan.index(sr[::-1])
        pcProfit += mult * profit[indx]
      
      else:
        sr2 = sr[:iter] + 'X' + sr[iter+1:]
        
        if sr2 in patternComputer:
          indx = patternComputer.index(sr2)
          pcProfit += mult * profit[indx]
        
        elif sr2[::-1] in patternComputer:
          indx = patternComputer.index(sr2[::-1])
          pcProfit += mult * profit[indx]

      if sl in patternMan:
        indx = patternMan.index(sl)
        pcProfit += mult * profit[indx]
      
      elif sl[::-1] in patternMan:
        indx = patternMan.index(sl[::-1])
        pcProfit += mult * profit[indx]

      else:
        sl2 = sl[:iter] + 'X' + sl[iter+1:]
        
        if sl2 in patternComputer:
          indx = patternComputer.index(sl2)
          pcProfit += mult * profit[indx]
        
        elif sl2[::-1] in patternComputer:
          indx = patternComputer.index(sl2[::-1])
          pcProfit += mult * profit[indx]

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
        pcProfit += mult * profit[indx]
      
      elif su[::-1] in patternMan:
        indx = patternMan.index(su[::-1])
        pcProfit += mult * profit[indx]

      else:
        su2 = su[:iter] + 'X' + su[iter+1:]
        
        if su2 in patternComputer:
          indx = patternComputer.index(su2)
          pcProfit += mult * profit[indx]
        
        elif su2[::-1] in patternComputer:
          indx = patternComputer.index(su2[::-1])
          pcProfit += mult * profit[indx]

      if sh in patternMan:
        indx = patternMan.index(sh)
        pcProfit += mult * profit[indx]

      elif sh[::-1] in patternMan:
        indx = patternMan.index(sh[::-1])
        pcProfit += mult * profit[indx]
      
      else:
        sh2 = sh[:iter] + 'X' + sh[iter+1:]
        
        if sh2 in patternComputer:
          indx = patternComputer.index(sh2)
          pcProfit += mult * profit[indx]

        elif sh2[::-1] in patternComputer:
          indx = patternComputer.index(sh2[::-1])
          pcProfit += mult * profit[indx]
    
    return pcProfit / 290082081


    else:
      
      state[x][y] = '-'
      mult = -1 #pcTurn * 1 + (1-pcTurn) * -1
      manProfit = 0
      #diagonal right left
      for iter in range(5):
        pr = x + iter #r for right diagonal
        qr = y - iter #l for left diagonal
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
          manProfit += mult * profit[indx]
        
        elif sr[::-1] in patternComputer:
          indx = patternComputer.index(sr[::-1])
          manProfit += mult * profit[indx]
        
        else:
          sr2 = sr[:iter] + 'O' + sr[iter+1:]
          
          if sr2 in patternMan:
            indx = patternMan.index(sr2)
            manProfit += mult * profit[indx]
          
          elif sr2[::-1] in patternMan:
            indx = patternMan.index(sr2[::-1])
            manProfit += mult * profit[indx]

        if sl in patternComputer:
          indx = patternComputer.index(sl)
          manProfit += mult * profit[indx]
        
        elif sl[::-1] in patternComputer:
          indx = patternComputer.index(sl[::-1])
          manProfit += mult * profit[indx]

        else:
          sl2 = sl[:iter] + 'O' + sl[iter+1:]
          
          if sl2 in patternMan:
            indx = patternMan.index(sl2)
            manProfit += mult * profit[indx]
          
          elif sl2[::-1] in patternMan:
            indx = patternMan.index(sl2[::-1])
            manProfit += mult * profit[indx]

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
          manProfit += mult * profit[indx]
        
        elif su[::-1] in patternComputer:
          indx = patternComputer.index(su[::-1])
          manProfit += mult * profit[indx]

        else:
          su2 = su[:iter] + 'O' + su[iter+1:]
          
          if su2 in patternMan:
            indx = patternMan.index(su2)
            manProfit += mult * profit[indx]
          
          elif su2[::-1] in patternMan:
            indx = patternMan.index(su2[::-1])
            manProfit += mult * profit[indx]

        if sh in patternComputer:
          indx = patternComputer.index(sh)
          manProfit += mult * profit[indx]

        elif sh[::-1] in patternComputer:
          indx = patternComputer.index(sh[::-1])
          manProfit += mult * profit[indx]
        
        else:
          sh2 = sh[:iter] + 'O' + sh[iter+1:]
          
          if sh2 in patternMan:
            indx = patternMan.index(sh2)
            manProfit += mult * profit[indx]

          elif sh2[::-1] in patternMan:
            indx = patternMan.index(sh2[::-1])
            manProfit += mult * profit[indx]
      
      return manProfit / 290082081
