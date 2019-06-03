class LogSystem:

    def __init__(self):
        self.log = {}

    def decompose(self, timestamp):
        us = timestamp.split(':')
        year, month, day, hour, minute, second = us[0], us[1], us[2], us[3], us[4], us[5]
        return year, month, day, hour, minute, second

    def put(self, id: int, timestamp: str) -> None:

        year, month, day, hour, minute, second = self.decompose(timestamp)
        log = self.log
        if year not in log:
            log[year] = {}
        log = log[year]
        if month not in log:
            log[month] = {}
        log = log[month]

        if day not in log:
            log[day] = {}
        log = log[day]
        if hour not in log:
            log[hour] = {}
        log = log[hour]

        if minute not in log:
            log[minute] = {}
        log = log[minute]

        if second not in log:
            log[second] = []
        log = log[second]

        log.append(id)
        # log[-1] = -1 # end

        # print (self.log )
    def retrieve(self, s: str, e: str, gra: str) -> List[int]:
        months = [str(i).zfill(2) for i in range(1, 13)]
        days = [str(i).zfill(2) for i in range(1, 32)]
        hours = [str(i).zfill(2) for i in range(0, 24)]
        minutes = [str(i).zfill(2) for i in range(0, 60)]
        seconds = [str(i).zfill(2) for i in range(0, 60)]

        def monthList(year, s, e ):

            su = s.split(':')
            eu = e.split(':')

            if su[:1] == eu[:1]:
                f = int(su[1])
                e = int(eu[1])
            else:
                if [year] == su[:1]:
                    f = int(su[1])
                    e = 12
                elif [year] == eu[:1]:

                    f = 1
                    e = int(eu[1])
                else:
                    f, e = 1, 12

            return [str(i).zfill(2) for i in range(f, e + 1)]

        def dayList(year, month, s, e ):
            su = s.split(':')
            eu = e.split(':')

            if su[:2] == eu[:2]:
                f = int(su[2])
                e = int(eu[2])
            else:
                if [year, month] == su[:2]:
                    f = int(su[2])
                    e = 31
                elif [year, month] == eu[:2]:

                    f = 1
                    e = int(eu[2])
                else:
                    f, e = 1, 31

            return [str(i).zfill(2) for i in range(f, e + 1)]
        def hourList(year, month, day, s, e ):
            su = s.split(':')
            eu = e.split(':')

            if su[:3] == eu[:3]:
                f = int(su[3])
                e = int(eu[3])
            else:
                if [year, month, day] == su[:3]:
                    f = int(su[3])
                    e = 23
                elif [year, month, day] == eu[:3]:

                    f = 0
                    e = int(eu[3])
                else:
                    f, e = 0, 23

            return [str(i).zfill(2) for i in range(f, e + 1)]

        def minuteList(year, month, day, hour , s , e):
            su = s.split(':')
            eu = e.split(':')

            if su[:4] == eu[:4]:
                f = int(su[4])
                e = int(eu[4])
            else:
                if [year,month, day, hour] == su[:4]:
                    f = int(su[4])
                    e = 59
                elif [year,month, day, hour] == eu[:4]:

                    f = 0
                    e = int(eu[4])
                else:
                    f, e = 0, 59

            return [str(i).zfill(2) for i in range(f, e + 1)]


        def secondList(year, month, day, hour, minute, s, e):
            su = s.split(':')
            eu = e.split(':')

            if su[:5] == eu[:5]:
                f = int(su[5])
                e = int(eu[5])
            else:
                if [year,month, day, hour, minute] == su[:5]:
                    f = int(su[5])
                    e = 59
                elif [year,month, day, hour, minute ] == eu[:5]:

                    f = 0
                    e = int(eu[5])
                else:
                    f, e = 0, 59

            return [str(i).zfill(2) for i in range(f, e + 1)]
        def lessEqGra(gra1, gra2):
            gm = {
                'Year': 10,
                'Month': 9,
                'Day': 8 ,
                'Hour': 7 ,
                'Minute': 6,
                'Second': 5
            }
            return gm[gra1] <= gm[gra2]
        def retrieveDay(s, e, gra):
            year0, month0, day0, hour0, minute0, second0 = self.decompose(s)

            year1, month1, day1, hour1, minute1, second1 = self.decompose(e)


            ret = []
            year = year0
            while year <= year1:

                log = self.log
                # print('begin cur year = ', year, ' cur ids = ', ret)
                if year not in log:
                    # print(year ,  'not in ')
                    year = str(int(year) + 1)

                else:

                    log = log[year]
                    if lessEqGra(gra, 'Month'):
                        months = monthList(year, s, e)
                    else:
                        months = [str(i).zfill(2) for i in range(1, 13)]
                    # print ('months = ', months)
                    for month in months:

                        if month not in log: continue
                        if lessEqGra(gra, 'Day'):
                            days = dayList(year, month, s, e)
                        else:
                            days = [str(i).zfill(2) for i in range(1, 32 )]

                        for day in days:
                            if day not in log[month]: continue
                            if lessEqGra(gra, 'Hour'):
                                hours = hourList(year,month,day, s,e)
                            else:
                                hours =  [str(i).zfill(2) for i in range(0, 24 )]

                            # print('hours = ' ,hours)

                            for hour in hours:
                                if hour not in log[month][day]: continue
                                if lessEqGra(gra, 'Minute'):
                                    minutes = minuteList(year,month, day, hour, s, e)

                                else:
                                    minutes = [str(i).zfill(2) for i in range(0, 60 )]

                                for minute in minutes:
                                    if minute not in log[month][day][hour]: continue

                                    if lessEqGra(gra, 'Second'):
                                        seconds = secondList(year, month ,day ,hour, minute, s, e)
                                    else:
                                        seconds = [str(i).zfill(2) for i in range(0, 60 )]

                                    for second in seconds:
                                        if second not in log[month][day][hour][minute]:
                                            continue
                                        ret.extend(log[month][day][hour][minute][second])

                    year = str(int(year) + 1)
            return ret

        return retrieveDay(s, e, gra)
