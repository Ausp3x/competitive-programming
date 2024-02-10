# -*- coding: utf-8 -*-
"""
Created on Wed Nov  8 07:35:49 2023

@author: Ausp3x
"""

from mpmath import *
mp.dps = 100

# values come from IERS 2010
a = mpf('6378136.6')
f = 1 / mpf('298.257222101')
e = sqrt(1 - (1 - f)**2)

# Annular Solar Eclipse of 2023 October 14
TDT, ΔT = mpf('18'), mpf('71.3') / mpf('3600')
T_i, T_f = mpf('-5'), mpf('5')
B = {
     'x':      [mpf('0.16966'), mpf('0.45855'),  mpf('0.00003'), mpf('-0.00001')],
     'y':      [mpf('0.33486'), mpf('-0.24137'), mpf('0.00002'), mpf('0.00000')],
     'd':      [mpf('-8.2442'), mpf('-0.0149'),  mpf('0.0000')],
     'μ':      [mpf('93.5017'), mpf('15.0035'),  mpf('-0.0000')],
     'l_1':    [mpf('0.56433'), mpf('-0.00009'), mpf('-0.00001')],
     'l_2':    [mpf('0.01808'), mpf('-0.00009'), mpf('-0.00001')],
     'tanf_1': [mpf('0.0046882')],
     'tanf_2': [mpf('0.0046648')],
    }
for x in ['x', 'y', 'd', 'μ', 'l_1', 'l_2']:
    i = 0
    for k in B[x]:
        if i == 0:
            B['d' + x] = []
            i += 1
            continue

        B['d' + x].append(i * k)
        i += 1

def getMB(x, t):
    if x == 'sind':
        i = 1
        d = 0
        for k in B['d']:
            d += k * i
            i *= t
        
        return sin(radians(d))
        
    if x == 'cosd':
        i = 1
        d = 0
        for k in B['d']:
            d += k * i
            i *= t

        return cos(radians(d))

    i = 1
    res = 0
    for k in B[x]:
        res += k * i
        i *= t
        
    return radians(res) if x == 'μ' or x == 'dd' or x == 'dμ' else res

def getAB(x, t):
    match x:
        case 'ρ_1':
            return sqrt(1 - (e**2) * (getMB('cosd', t)**2))
        case 'ρ_2':
            return sqrt(1 - (e**2) * (getMB('sind', t)**2))
        case 'sind_1':
            return getMB('sind', t) / getAB('ρ_1', t)
        case 'cosd_1':
            return sqrt(1 - e**2) * getMB('cosd', t) / getAB('ρ_1', t)
        case 'sin(d_1 - d_2)':
            return (e**2) * getMB('sind', t) * getMB('cosd', t) / getAB('ρ_1', t) / getAB('ρ_2', t)
        case 'cos(d_1 - d_2)':
            return sqrt(1 - e**2) / getAB('ρ_1', t) / getAB('ρ_2', t)
        case _:
            return 'getAB() indexError'

# f_p = 0
# def inverseInterpolation(f, *argv):
#     t_0 = argv[0]
#     τ = mpf("0.001")

#     fs = [None for _ in range(6)]
#     for i in range(-2, 4):
#         fs[i] = f(t_0 + i * τ, *argv[1:])

#     Δ_2 =             fs[2] -      fs[1] -      fs[0] +     fs[-1]
#     Δ_3 =             fs[2] -  3 * fs[1] +  3 * fs[0] -     fs[-1]
#     Δ_4 = fs[3] - 3 * fs[2] +  2 * fs[1] +  2 * fs[0] - 3 * fs[-1] + fs[-2]
#     Δ_5 = fs[3] - 5 * fs[2] + 10 * fs[1] - 10 * fs[0] + 5 * fs[-1] - fs[-2]

#     p = [0, 0]
#     cnt = 0
#     for _ in range(1000):
#         B_2 = p[cnt] * (p[cnt] - 1) / 4
#         B_3 = p[cnt] * (p[cnt] - mpf('0.5')) * (p[cnt] - 1) / 6
#         B_4 = (p[cnt] + 1) * p[cnt] * (p[cnt] - 1) * (p[cnt] - 2) / 48
#         B_5 = (p[cnt] + 1) * p[cnt] * (p[cnt] - mpf('0.5')) * (p[cnt] - 1) * (p[cnt] - 2) / 120

#         p[cnt ^ 1] = (fs[0] + B_2 * Δ_2 + B_3 * Δ_3 + B_4 * Δ_4 + B_5 * Δ_5) / (fs[0] - fs[1]) 
#         cnt ^= 1
    
#         if p[cnt].imag == 0 and p[cnt ^ 1].imag == 0:
#             if abs(p[cnt].real - p[cnt ^ 1].real) < mpf('0.000001'):
#                 return t_0 + p[cnt] * τ
    
#     return None

def successiveApproximation(f, *argv):
    t, τ = [argv[0], 0], mpf('0.000000000000000001')
    cnt = 0
    for _ in range(100):
        t[cnt ^ 1] = t[cnt] - f(t[cnt], *argv[1:]) / ((f(t[cnt] + τ, *argv[1:]) - f(t[cnt] - τ, *argv[1:])) / (2 * τ))
        cnt ^= 1

        if abs(t[cnt] - t[cnt ^ 1]) < mpf('0.000000001'):
            # print(_)
            return t[cnt]

    # print(100)
    return None

def getLongitudeAndLatitude(t, ξ, η_1, ζ_1):
    μ = getMB('μ', t - ΔT)
    sind_1 = getAB('sind_1', t)
    cosd_1 = getAB('cosd_1', t)

    ϕ_1 = asin(η_1 * cosd_1 + ζ_1 * sind_1)
    θ = 2 * atan(ξ / (cos(ϕ_1) - η_1 * sind_1 + ζ_1 * cosd_1))

    ϕ = atan(tan(ϕ_1) / sqrt(1 - e**2))
    λ = θ - μ
    if λ < -pi:
        λ += 2 * pi
    elif λ > pi:
        λ -= 2 * pi

    return [λ, ϕ]

# t must be in decimal hours
def convertToUT1(t):
    T = TDT + t - ΔT 
    h = int(T)
    m = int(frac(abs(T)) * 60)
    s = int(frac(frac(abs(T)) * 60) * 60000)
    
    if s % 10 >= 5:
        s += 10
    s //= 10
    if s >= 6000:
        m += 1
        s -= 6000
    if m >= 60:
        h += pow(-1, h < 0)
        m -= 60

    return str(h).zfill(2) + ':' + str(m).zfill(2) + ':' + str(s // 100).zfill(2) + '.' + str(s % 100).zfill(2)

# α must be in radians
def convertToGeodetic(α, opt):
    α = degrees(α)
    deg = int(α)
    amn = int(frac(abs(α)) * 60000)

    if amn % 10 >= 5:
        amn += 10
    amn //= 10
    if amn >= 6000:
        deg += pow(-1, deg < 0)
        amn -= 6000 

    res = str(abs(deg)).zfill(2 + opt) + '°' + str(amn // 100).zfill(2) + '.' + str(amn % 100).zfill(2) + '\''
    if opt == 0:
        res += 'N' if deg >= 0 else 'S'
    elif opt == 1:
        res += 'E' if deg >= 0 else 'W'
    
    return res

def convertDuration(dur):
    dur = abs(dur) * 60
    m = int(dur)
    s = int(frac(dur) * 60000)
    
    if s % 10 >= 5:
        s += 10
    s //= 10
    if s >= 6000:
        m += 1
        s -= 6000

    return str(m).zfill(2) + 'm' + str(s // 100).zfill(2) + '.' + str(s % 100).zfill(2) + 's'

def convertPathWidth(wid):
    wid = abs(wid) * a / 1000

    return nstr(wid, 5) + ' km'

file = open('General Circumstances.txt', 'w', encoding = 'utf-8')
mag = None
obs = None
generalCircumstances = {}
for k in ['GE', 'EC'
          'P1', 'P2', 'P3', 'P4', 'PN1', 'PS1', 'PN2', 'PS2', 
          'U1', 'U2', 'U3', 'U4', 'UN1', 'US1', 'UN2', 'US2', 
          'C1', 'C2']:
    generalCircumstances[k] = None
curves = {}
for k in ['PN', 'PS', 'UN', 'US', 'C']:
    curves[k] = None
    
def printResults(keys, opt):
    for k in keys:
        t, λ, ϕ = generalCircumstances[k][:3]
        if opt == 1:
            if t == None:
                file.write(k.ljust(3, ' ') + ' | None        | None       | None\n')
                continue

            if λ == None:
                file.write(k.ljust(3, ' ') + ' | ' + convertToUT1(t) + ' | None       | None\n')
                continue
            
            file.write(k.ljust(3, ' ')  + ' | ' + convertToUT1(t) + ' | ' + convertToGeodetic(ϕ, 0) + ' | ' + convertToGeodetic(λ, 1))
            if k == 'GE':
                dur, wid = generalCircumstances[k][3:]
                if dur == None:
                    file.write(' | None      | None')
                else:
                    file.write(' | ' + convertDuration(dur) + ' | ' + convertPathWidth(wid))
            file.write('\n')
        elif opt == 2:
            if λ == None:
                continue

            file.write(nstr(degrees(λ), n = 8) + ', ' + nstr(degrees(ϕ), n = 8) + '\n')

    return



####################################################################################################
def D_1_1(t, opt):
    x = getMB('x', t)
    y = getMB('y', t)
    l_1 = getMB('l_1', t)
    ρ_1 = getAB('ρ_1', t)

    m = sqrt(x**2 + y**2)
    y_1 = y / ρ_1
    m_1 = sqrt(x**2 + y_1**2)
    ρ = m / m_1

    return x**2 + y**2 - (pow(-1, opt) * abs(l_1) + ρ)**2

def getFirstAndLastContactsOfPenumbra():
    ks = ['P1', 'P2', 'P3', 'P4']
    # ts = [inverseInterpolation(D_1_1, mpf('-3'), 0), inverseInterpolation(D_1_1, mpf('-1'), 1),
    #       inverseInterpolation(D_1_1, mpf('1'), 1), inverseInterpolation(D_1_1, mpf('3'), 0)]
    ts = [successiveApproximation(D_1_1, T_i, 0), successiveApproximation(D_1_1, T_i, 1),
          successiveApproximation(D_1_1, T_f, 1), successiveApproximation(D_1_1, T_f, 0)]
    for k, t in zip(ks, ts):
        if t == None:
            generalCircumstances[k] = [None, None, None]
            continue

        x = getMB('x', t)
        y = getMB('y', t)
        ρ_1 = getAB('ρ_1', t)
        
        y_1 = y / ρ_1
        m_1 = sqrt(x**2 + y_1**2)
        
        λ, ϕ = getLongitudeAndLatitude(t, x / m_1, y_1 / m_1, 0)
        generalCircumstances[k] = [t, λ, ϕ]

    return
####################################################################################################
def D_1_2(t, opt):
    x = getMB('x', t)
    y = getMB('y', t)
    l_2 = getMB('l_2', t)
    ρ_1 = getAB('ρ_1', t)

    m = sqrt(x**2 + y**2)
    y_1 = y / ρ_1
    m_1 = sqrt(x**2 + y_1**2)
    ρ = m / m_1

    return x**2 + y**2 - (pow(-1, opt) * abs(l_2) + ρ)**2

def getFirstAndLastContactsOfUmbra():
    ks = ['U1', 'U2', 'U3', 'U4']
    # ts = [inverseInterpolation(D_1_2, mpf('-2'), 0), inverseInterpolation(D_1_2, mpf('-2'), 1),
    #       inverseInterpolation(D_1_2, mpf('2'), 1), inverseInterpolation(D_1_2, mpf('2'), 0)]
    ts = [successiveApproximation(D_1_2, T_i, 0), successiveApproximation(D_1_2, T_i, 1),
          successiveApproximation(D_1_2, T_f, 1), successiveApproximation(D_1_2, T_f, 0)]
    for k, t in zip(ks, ts):
        if t == None:
            generalCircumstances[k] = [None, None, None]
            continue

        x = getMB('x', t)
        y = getMB('y', t)
        ρ_1 = getAB('ρ_1', t)
        
        y_1 = y / ρ_1 
        m_1 = sqrt(x**2 + y_1**2)
        
        λ, ϕ = getLongitudeAndLatitude(t, x / m_1, y_1 / m_1, 0)
        generalCircumstances[k] = [t, λ, ϕ]

    return
####################################################################################################
def D_2(t):
    x = getMB('x', t)
    y = getMB('y', t)
    ρ_1 = getAB('ρ_1', t)

    y_1 = y / ρ_1

    return x**2 + y_1**2 - 1

def getBeginningAndEndOfCentralLine():
    ks = ['C1', 'C2']
    # ts = [inverseInterpolation(D_2, mpf('-2')), inverseInterpolation(D_2, mpf('2'))]
    ts = [successiveApproximation(D_2, T_i), successiveApproximation(D_2, T_f)]
    for k, t in zip(ks, ts):
        if t == None:
            generalCircumstances[k] = [None, None, None]
            continue

        x = getMB('x', t)
        y = getMB('y', t)
        ρ_1 = getAB('ρ_1', t)

        y_1 = y / ρ_1
        
        λ, ϕ = getLongitudeAndLatitude(t, x, y_1, 0)
        generalCircumstances[k] = [t, λ, ϕ]

    return
####################################################################################################
def getSinQCosQPenumbral(t, opt):
    x = getMB('x', t)
    y = getMB('y', t)
    sind = getMB('sind', t)
    cosd = getMB('cosd', t)
    l_1 = getMB('l_1', t)
    tanf_1 = getMB('tanf_1', t)
    dd = getMB('dd', t)
    dμ = getMB('dμ', t)
    dx = getMB('dx', t)
    dy = getMB('dy', t)
    dl_1 = getMB('dl_1', t)

    da = -dl_1 - dμ * x * cosd * tanf_1 + y * dd * tanf_1
    db = -dy   + dμ * x * sind          + l_1 * dd * tanf_1
    dc = dx    + dμ * y * sind          + l_1 * dμ * tanf_1 * cosd

    sinQ = (-da * dc + pow(-1, opt) * db * sqrt(-da**2 + db**2 + dc**2)) / (db**2 + dc**2)
    cosQ = (da + dc * sinQ) / db

    return [sinQ, cosQ]

def D_3_1(t, opt):
    x = getMB('x', t)
    y = getMB('y', t)
    l_1 = getMB('l_1', t)
    ρ_1 = getAB('ρ_1', t)
    sinQ, cosQ = getSinQCosQPenumbral(t, opt)

    return (x - l_1 * sinQ)**2 + ((y - l_1 * cosQ) / ρ_1)**2 - 1

def getExtremePointsOfPenumbralLimits():
    ks = ['PN1', 'PS1', 'PN2', 'PS2']
    # ts = [inverseInterpolation(D_3_1, mpf('-3'), 0), inverseInterpolation(D_3_1, mpf('-3'), 1),
    #       inverseInterpolation(D_3_1, mpf('3'), 0), inverseInterpolation(D_3_1, mpf('3'), 1)]
    ts = [successiveApproximation(D_3_1, T_i, 0), successiveApproximation(D_3_1, T_i, 1),
          successiveApproximation(D_3_1, T_f, 0), successiveApproximation(D_3_1, T_f, 1)]
    for i in range(4):
        if ts[i] == None:
            generalCircumstances[ks[i]] = [None, None, None]
            continue

        x = getMB('x', ts[i])
        y = getMB('y', ts[i])
        l_1 = getMB('l_1', ts[i])
        ρ_1 = getAB('ρ_1', ts[i])
        sinQ, cosQ = getSinQCosQPenumbral(ts[i], i % 2)

        ξ_1 = x - l_1 * sinQ
        η_1 = (y - l_1 * cosQ) / ρ_1

        λ, ϕ = getLongitudeAndLatitude(ts[i], ξ_1, η_1, 0)
        generalCircumstances[ks[i]] = [ts[i], λ, ϕ]

        if i % 2 and l_1 * cosQ <= 0:
            generalCircumstances[ks[i]], generalCircumstances[ks[i - 1]] = generalCircumstances[ks[i - 1]], generalCircumstances[ks[i]]

    return
####################################################################################################
def getSinQCosQUmbral(t, opt):
    x = getMB('x', t)
    y = getMB('y', t)
    sind = getMB('sind', t)
    cosd = getMB('cosd', t)
    l_2 = getMB('l_2', t)
    tanf_2 = getMB('tanf_2', t)
    dd = getMB('dd', t)
    dμ = getMB('dμ', t)
    dx = getMB('dx', t)
    dy = getMB('dy', t)
    dl_2 = getMB('dl_2', t)

    da = -dl_2 - dμ * x * cosd * tanf_2 + y * dd * tanf_2
    db = -dy   + dμ * x * sind          + l_2 * dd * tanf_2
    dc = dx    + dμ * y * sind          + l_2 * dμ * tanf_2 * cosd

    sinQ = (-da * dc + pow(-1, opt) * db * sqrt(-da**2 + db**2 + dc**2)) / (db**2 + dc**2)
    cosQ = (da + dc * sinQ) / db

    return [sinQ, cosQ]

def D_3_2(t, opt):
    x = getMB('x', t)
    y = getMB('y', t)
    l_2 = getMB('l_2', t)
    ρ_1 = getAB('ρ_1', t)
    sinQ, cosQ = getSinQCosQUmbral(t, opt)

    return (x - l_2 * sinQ)**2 + ((y - l_2 * cosQ) / ρ_1)**2 - 1

def getExtremePointsOfUmbralLimits():
    ks = ['UN1', 'US1', 'UN2', 'US2']
    # ts = [inverseInterpolation(D_3_2, mpf('-3'), 0), inverseInterpolation(D_3_2, mpf('-3'), 1),
    #       inverseInterpolation(D_3_2, mpf('3'), 0), inverseInterpolation(D_3_2, mpf('3'), 1)]
    ts = [successiveApproximation(D_3_2, T_i, 0), successiveApproximation(D_3_2, T_i, 1),
          successiveApproximation(D_3_2, T_f, 0), successiveApproximation(D_3_2, T_f, 1)]
    for i in range(4):
        if ts[i] == None:
            generalCircumstances[ks[i]] = [None, None, None]
            continue

        x = getMB('x', ts[i])
        y = getMB('y', ts[i])
        l_2 = getMB('l_2', ts[i])
        ρ_1 = getAB('ρ_1', ts[i])
        sinQ, cosQ = getSinQCosQUmbral(ts[i], i % 2)

        ξ = x - l_2 * sinQ
        η_1 = (y - l_2 * cosQ) / ρ_1

        λ, ϕ = getLongitudeAndLatitude(ts[i], ξ, η_1, 0)
        generalCircumstances[ks[i]] = [ts[i], λ, ϕ]

        if i % 2 and l_2 * cosQ <= 0:
            generalCircumstances[ks[i]], generalCircumstances[ks[i - 1]] = generalCircumstances[ks[i - 1]], generalCircumstances[ks[i]]

    return
####################################################################################################
def D_4(t):
    x = getMB('x', t)
    y = getMB('y', t)
    dx = getMB('dx', t)
    dy = getMB('dy', t)

    return x * dx + y * dy

def getGreatestEclipse(ecl):
    global mag, obs
    # t = inverseInterpolation(D_4, mpf('0'))
    t = successiveApproximation(D_4, mpf('0'))

    x = getMB('x', t)
    y = getMB('y', t)
    l_1 = getMB('l_1', t)
    l_2 = getMB('l_2', t)
    sind = getMB('sind', t)
    cosd = getMB('cosd', t)
    tanf_1 = getMB('tanf_1', t)
    tanf_2 = getMB('tanf_2', t)
    dx = getMB('dx', t)
    dy = getMB('dy', t)
    dd = getMB('dd', t)
    dμ = getMB('dμ', t)
    ρ_1 = getAB('ρ_1', t)
    ρ_2 = getAB('ρ_2', t)
    sind_1Minusd_2 = getAB('sin(d_1 - d_2)', t)
    cosd_1Minusd_2 = getAB('cos(d_1 - d_2)', t)

    m = sqrt(x**2 + y**2)
    y_1 = y / ρ_1
    m_1 = sqrt(x**2 + y_1**2)

    if ecl == 1:
        ξ = x / m_1
        η_1 = y_1 / m_1
        ζ_1 = 0
        η = y / m_1
        ζ = 0

        Δ = m - m / m_1
        mag = (l_1 - Δ) / (l_1 + l_2)

        r_s = 1
        r_m = (l_1 - l_2) / (l_1 + l_2)
        hyp = r_s + r_m - 2 * mag
        A = acos((r_m**2 + hyp**2 - r_s**2) / (2 * r_m * hyp))
        B = acos((r_s**2 + hyp**2 - r_m**2) / (2 * r_s * hyp))
        obs = (r_m**2 * A + r_s**2 * B - r_m**2 * sin(A) * cos(A) - r_s**2 * sin(B) * cos(B)) / pi
        
        λ, ϕ = getLongitudeAndLatitude(t, ξ, η_1, ζ_1)
        generalCircumstances['GE'] = [t, λ, ϕ, None, None]
    elif ecl == 2:
        ξ = x
        η_1 = y / ρ_1
        ζ_1 = sqrt(1 - ξ**2 - η_1**2)
        η = y
        ζ = ρ_2 * (ζ_1 * cosd_1Minusd_2 - η_1 * sind_1Minusd_2)

        L_1 = l_1 - ζ * tanf_1
        L_2 = l_2 - ζ * tanf_2
        mag = (L_1 - L_2) / (L_1 + L_2)
        
        obs = mag**2
        
        dξ = dμ * (-y * sind + ζ * cosd)
        dη = dμ * x * sind - dd * ζ
        n = sqrt((dx - dξ)**2 + (dy - dη)**2)
        
        λ, ϕ = getLongitudeAndLatitude(t, ξ, η_1, ζ_1)
        dur = abs(2 * L_2 / n)
        wid = abs(2 * L_2 / sqrt(ζ**2 + ((ξ / n) * (dx - dξ) + (η / n) * (dy - dη))**2))
        generalCircumstances['GE'] = [t, λ, ϕ, dur, wid]

    return
####################################################################################################
def D_5(t):
    x = getMB('x', t)

    return x

def getEquatorialConjunction(ecl):
    # t = inverseInterpolation(D_5, mpf('0'))
    t = successiveApproximation(D_5, mpf('0'))

    x = getMB('x', t)
    y = getMB('y', t)
    ρ_1 = getAB('ρ_1', t)

    y_1 = y / ρ_1

    if ecl == 1:
        generalCircumstances['EC'] = [t, None, None]
    elif ecl == 2:
        λ, ϕ = getLongitudeAndLatitude(t, x, y_1, 0)
        generalCircumstances['EC'] = [t, λ, ϕ]

    return
####################################################################################################



####################################################################################################

####################################################################################################



getFirstAndLastContactsOfPenumbra()
getFirstAndLastContactsOfUmbra()
getBeginningAndEndOfCentralLine()
getExtremePointsOfPenumbralLimits()
getExtremePointsOfUmbralLimits()
getGreatestEclipse(2)
getEquatorialConjunction(2)

file.write('Eclipse Magnitude   | ' + nstr(mag) + '\n')
file.write('Eclipse Obscuration | ' + nstr(obs) + '\n')
printResults(['GE', 'EC', 'P1', 'P2', 'P3', 'P4', 'PN1', 'PS1', 'PN2', 'PS2', 'U1', 'U2', 'U3', 'U4', 'UN1', 'US1', 'UN2', 'US2', 'C1', 'C2'], 1)
# printResults(['GE', 'EC', 'P1', 'P2', 'P3', 'P4', 'PN1', 'PS1', 'PN2', 'PS2', 'U1', 'U2', 'U3', 'U4', 'UN1', 'US1', 'UN2', 'US2', 'C1', 'C2'], 2)
