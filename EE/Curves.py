# -*- coding: utf-8 -*-
"""
Created on Mon Nov 13 08:18:53 2023

@author: Ausp3x
"""

from mpmath import *
mp.dps = 100

# values come from IERS 2010
a = mpf('6378136.6')
f = 1 / mpf('298.257222101')
e = sqrt(1 - (1 - f)**2)

# Total Solar Eclipse of 2019 July 02
TDT, ΔT = mpf('19'), mpf('69.6') / mpf('3600')
T_i, T_f = mpf('-5'), mpf('5')
B = {
     'x':      [mpf('-0.21563'),  mpf('0.56621'),  mpf('0.00003'),  mpf('-0.00001')],
     'y':      [mpf('-0.65071'),  mpf('0.01064'),  mpf('-0.00013'), mpf('-0.00000')],
     'd':      [mpf('23.0129'),   mpf('-0.0032'),  mpf('-0.0000')],
     'μ':      [mpf('103.9797'),  mpf('14.9995'),  mpf('0.0000')],
     'l_1':    [mpf('0.53765'),   mpf('-0.00009'), mpf('-0.00001')],
     'l_2':    [mpf('-0.00847'),  mpf('-0.00009'), mpf('-0.00001')],
     'tanf_1': [mpf('0.0045984')],
     'tanf_2': [mpf('0.0045755')],
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
    
    if x == 'μ':
        i = 1
        μ = 0
        for k in B['μ']:
            μ += k * i
            i *= t

        return radians(μ)

    if x == 'dd':
        i = 1
        dd = 0
        for k in B['dd']:
            dd += k * i
            i *= t

        return radians(dd)

    if x == 'dμ':
        i = 1
        dμ = 0
        for k in B['dμ']:
            dμ += k * i
            i *= t

        return radians(dμ)

    i = 1
    res = 0
    for k in B[x]:
        res += k * i
        i *= t
        
    return res

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
def inverseInterpolation(f, *argv):
    t_0 = argv[0]
    τ = mpf("0.001")

    fs = [None for _ in range(6)]
    for i in range(-2, 4):
        fs[i] = f(t_0 + i * τ, *argv[1:])

    Δ_1 =                          fs[1] -      fs[0]
    Δ_2 =             fs[2] -      fs[1] -      fs[0] +     fs[-1]
    Δ_3 =             fs[2] -  3 * fs[1] +  3 * fs[0] -     fs[-1]
    Δ_4 = fs[3] - 3 * fs[2] +  2 * fs[1] +  2 * fs[0] - 3 * fs[-1] + fs[-2]
    Δ_5 = fs[3] - 5 * fs[2] + 10 * fs[1] - 10 * fs[0] + 5 * fs[-1] - fs[-2]

    p = [0, 0]
    cnt = 0
    for _ in range(1000):
        B_2 = p[cnt] * (p[cnt] - 1) / 4
        B_3 = p[cnt] * (p[cnt] - mpf('0.5')) * (p[cnt] - 1) / 6
        B_4 = (p[cnt] + 1) * p[cnt] * (p[cnt] - 1) * (p[cnt] - 2) / 48
        B_5 = (p[cnt] + 1) * p[cnt] * (p[cnt] - mpf('0.5')) * (p[cnt] - 1) * (p[cnt] - 2) / 120

        p[cnt ^ 1] = (fs[0] + B_2 * Δ_2 + B_3 * Δ_3 + B_4 * Δ_4 + B_5 * Δ_5) / (fs[0] - fs[1]) 
        cnt ^= 1

        if abs(p[cnt] - p[cnt ^ 1]) < mpf('0.000001'):
            return t_0 + p[cnt] * τ
        
    return None

def getLongitudeAndLatitude(t, ξ, η_1, ζ_1):
    μ = getMB('μ', t)
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
    T = TDT - ΔT + t
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

file = open('Curves.txt', 'w', encoding = 'utf-8')
def printResults(k, ts, λs, ϕs, opt):
    match opt:
        case 1:
            file.write(k + '\n')
            for t, λ, ϕ in zip(ts, λs, ϕs):
                file.write(convertToUT1(t) + '  ' + convertToGeodetic(ϕ, 0) + '  ' + convertToGeodetic(λ, 1) + '\n')
        case 2:
            for λ, ϕ in zip(λs, ϕs):
                file.write(nstr(degrees(λ), n = 8) + ', ' + nstr(degrees(ϕ), n = 8) + '\n')
        case _:
            print('printResults() indexError')

    return



def getRisingAndSettingCurves(𝜏):
    t = T_i + ΔT
    ts, λs, ϕs = [], [], []
    while t <= T_f + ΔT:
        x = getMB('x', t)
        y = getMB('y', t)
        l_1 = getMB('l_1', t)
        ρ_1 = getAB('ρ_1', t)
        m = sqrt(x**2 + y**2)
        M = 2 * atan(x / (y + m))

        for i in range(2):
            ρ = 1
            cnt = 5
            for j in range(cnt):
                A = 2 * asin(sqrt((l_1 + m - ρ) * (l_1 - m + ρ) / (4 * m * ρ)))
                γ = M + pow(-1, i) * A
                
                if γ.imag != 0:
                    break

                ξ = ρ * sin(γ)
                η_1 = ρ * cos(γ) / ρ_1
                γ2 = 2 * atan(ξ / (η_1 + sqrt(ξ**2 + η_1**2)))
                ρ = sin(γ2) / sin(γ)

                if j == cnt - 1:
                    if cos(M - γ) < 0:
                        continue

                    λ, ϕ = getLongitudeAndLatitude(t, sin(γ2), cos(γ2), 0)
                    ts.append(t)
                    λs.append(λ)
                    ϕs.append(ϕ)

        t += 𝜏
    
    return ['Rising and Setting Curves', ts, λs, ϕs]

def getCurvesOfMaximumEclipseInTheHorizon(𝜏):
    t = T_i + ΔT
    ts, λs, ϕs = [], [], []
    while t <= T_f + ΔT:
        x = getMB('x', t)
        y = getMB('y', t)
        sind = getMB('sind', t)
        cosd = getMB('cosd', t)
        l_1 = getMB('l_1', t)
        tanf_1 = getMB('tanf_1', t)
        dμ = getMB('dμ', t)
        dd = getMB('dd', t)
        dx = getMB('dx', t)
        dy = getMB('dy', t)
        dl_1 = getMB('dl_1', t)
        ρ_1 = getAB('ρ_1', t)

        da = -dl_1 - dμ * x * cosd * tanf_1 + y * dd * tanf_1
        db = -dy   + dμ * x * sind          + l_1 * dd * tanf_1
        dc = dx    + dμ * y * sind          + l_1 * dμ * tanf_1 * cosd

        for i in range(2):
            sinQ = (-da * dc + pow(-1, i) * db * sqrt(-da**2 + db**2 + dc**2)) / (db**2 + dc**2)
            cosQ = (da + dc * sinQ) / db
            Q = 2 * atan(sinQ / (1 + cosQ))

            ρ = 1
            cnt = 5
            for j in range(cnt):
                sinγMinusQ = (x * cosQ - y * sinQ) / ρ
                γ = Q + asin((x * cosQ - y * sinQ) / ρ)

                if γ.imag != 0:
                    break

                ξ = ρ * sin(γ)
                η_1 = ρ * cos(γ) / ρ_1
                γ2 = 2 * atan(ξ / (η_1 + sqrt(ξ**2 + η_1**2)))
                ρ = sin(γ2) / sin(γ)

                if j == cnt - 1:
                    if sinγMinusQ > 1 or (x - ξ)**2 + (y - η_1 * ρ_1)**2 > l_1**2:
                        continue

                    λ, ϕ = getLongitudeAndLatitude(t, sin(γ2), cos(γ2), 0)
                    ts.append(t)
                    λs.append(λ)
                    ϕs.append(ϕ)

        t += 𝜏
    
    return ['Curves of Maximum Eclipse in the Horizon', ts, λs, ϕs]

def getCentralLine(𝜏):
    t = T_i + ΔT
    ts, λs, ϕs = [], [], []
    while t <= T_f + ΔT:
        x = getMB('x', t)
        y = getMB('y', t)
        ρ_1 = getAB('ρ_1', t)

        ξ = x
        η_1 = y / ρ_1
        ζ_1 = sqrt(1 - ξ**2 - η_1**2) 

        if ζ_1.imag != 0:
            t += 𝜏
            continue

        λ, ϕ = getLongitudeAndLatitude(t, ξ, η_1, ζ_1)
        ts.append(t)
        λs.append(λ)
        ϕs.append(ϕ)

        t += 𝜏
    
    return ['Central Line', ts, λs, ϕs]

def getNorthernAndSouthernLimitsOfThePenumbra(𝜏):
    t = T_i + ΔT
    ts, λs, ϕs = [], [], []
    while t <= T_f + ΔT:
        x = getMB('x', t)
        y = getMB('y', t)
        sind = getMB('sind', t)
        cosd = getMB('cosd', t)
        l_1 = getMB('l_1', t)
        tanf_1 = getMB('tanf_1', t)
        dμ = getMB('dμ', t)
        dd = getMB('dd', t)
        dx = getMB('dx', t)
        dy = getMB('dy', t)
        dl_1 = getMB('dl_1', t)
        ρ_1 = getAB('ρ_1', t)
        ρ_2 = getAB('ρ_2', t)
        sind_1Minusd_2 = getAB('sin(d_1 - d_2)', t)
        cosd_1Minusd_2 = getAB('cos(d_1 - d_2)', t)

        secSqrdf_1 = 1 + tanf_1**2
        da = -dl_1 - dμ * x * cosd * tanf_1 + y * dd * tanf_1
        db = -dy   + dμ * x * sind          + l_1 * dd * tanf_1
        dc = dx    + dμ * y * sind          + l_1 * dμ * tanf_1 * cosd

        for i in range(2):
            ζ = [0, 0]
            cnt = 0
            while True:
                k_1 = db**2 - 2 * db * dd * ζ[cnt] * secSqrdf_1        + dd**2 * ζ[cnt]**2 * secSqrdf_1**2 +\
                      dc**2 - 2 * dc * dμ * ζ[cnt] * cosd * secSqrdf_1 + dμ**2 * ζ[cnt]**2 * cosd**2 * secSqrdf_1**2
                k_2 = 2 * da * dc - 2 * da * dμ * ζ[cnt] * cosd * secSqrdf_1
                k_3 = da**2 - db**2 + 2 * db * dd * ζ[cnt] * secSqrdf_1 - dd**2 * ζ[cnt]**2 * secSqrdf_1**2

                sinQ = (-k_2 + pow(-1, i) * sqrt(k_2**2 - 4 * k_1 * k_3)) / (2 * k_1)
                cosQ = (da + (dc - dμ * ζ[cnt] * cosd * secSqrdf_1) * sinQ) / (db - dd * ζ[cnt] * secSqrdf_1)

                if sinQ.imag != 0:
                    break

                L_1 = l_1 - ζ[cnt] * tanf_1
                ξ = x - L_1 * sinQ
                η_1 = (y - L_1 * cosQ) / ρ_1
                ζ_1 = sqrt(1 - ξ**2 - η_1**2)

                if ζ_1.imag != 0:
                    break

                cnt ^= 1
                ζ[cnt] = ρ_2 * (ζ_1 * cosd_1Minusd_2 - η_1 * sind_1Minusd_2)
                ζ[cnt] = (ζ[cnt] + ζ[cnt ^ 1]) / 2

                if abs(ζ[cnt] - ζ[cnt ^ 1]) < mpf('0.000001'):
                    λ, ϕ = getLongitudeAndLatitude(t, ξ, η_1, ζ_1)
                    ts.append(t)
                    λs.append(λ)
                    ϕs.append(ϕ)
                    break

        t += 𝜏
    
    return ['Northern and Southern Limits of the Penumbra', ts, λs, ϕs]

def getNorthernAndSouthernLimitsOfTheUmbra(𝜏):
    t = T_i + ΔT
    ts, λs, ϕs = [], [], []
    while t <= T_f + ΔT:
        x = getMB('x', t)
        y = getMB('y', t)
        sind = getMB('sind', t)
        cosd = getMB('cosd', t)
        l_2 = getMB('l_2', t)
        tanf_2 = getMB('tanf_2', t)
        dμ = getMB('dμ', t)
        dd = getMB('dd', t)
        dx = getMB('dx', t)
        dy = getMB('dy', t)
        dl_2 = getMB('dl_2', t)
        ρ_1 = getAB('ρ_1', t)
        ρ_2 = getAB('ρ_2', t)
        sind_1Minusd_2 = getAB('sin(d_1 - d_2)', t)
        cosd_1Minusd_2 = getAB('cos(d_1 - d_2)', t)

        secSqrdf_2 = 1 + tanf_2**2
        da = -dl_2 - dμ * x * cosd * tanf_2 + y * dd * tanf_2
        db = -dy   + dμ * x * sind          + l_2 * dd * tanf_2
        dc = dx    + dμ * y * sind          + l_2 * dμ * tanf_2 * cosd

        for i in range(2):
            ζ = [0, 0]
            cnt = 0
            while True:
                k_1 = db**2 - 2 * db * dd * ζ[cnt] * secSqrdf_2        + dd**2 * ζ[cnt]**2 * secSqrdf_2**2 +\
                      dc**2 - 2 * dc * dμ * ζ[cnt] * cosd * secSqrdf_2 + dμ**2 * ζ[cnt]**2 * cosd**2 * secSqrdf_2**2
                k_2 = 2 * da * dc - 2 * da * dμ * ζ[cnt] * cosd * secSqrdf_2
                k_3 = da**2 - db**2 + 2 * db * dd * ζ[cnt] * secSqrdf_2 - dd**2 * ζ[cnt]**2 * secSqrdf_2**2

                sinQ = (-k_2 + pow(-1, i) * sqrt(k_2**2 - 4 * k_1 * k_3)) / (2 * k_1)
                cosQ = (da + (dc - dμ * ζ[cnt] * cosd * secSqrdf_2) * sinQ) / (db - dd * ζ[cnt] * secSqrdf_2)

                if sinQ.imag != 0:
                    break

                L_2 = l_2 - ζ[cnt] * tanf_2
                ξ = x - L_2 * sinQ
                η_1 = (y - L_2 * cosQ) / ρ_1
                ζ_1 = sqrt(1 - ξ**2 - η_1**2)

                if ζ_1.imag != 0:
                    break

                cnt ^= 1
                ζ[cnt] = ρ_2 * (ζ_1 * cosd_1Minusd_2 - η_1 * sind_1Minusd_2)
                ζ[cnt] = (ζ[cnt] + ζ[cnt ^ 1]) / 2

                if abs(ζ[cnt] - ζ[cnt ^ 1]) < mpf('0.000001'):
                    λ, ϕ = getLongitudeAndLatitude(t, ξ, η_1, ζ_1)
                    ts.append(t)
                    λs.append(λ)
                    ϕs.append(ϕ)
                    break

        t += 𝜏
    
    return ['Northern and Southern Limits of the Umbra', ts, λs, ϕs]

def getOutlineCurvesOfThePenumbra(𝜏):
    t = T_i + ΔT
    ts, λs, ϕs = [], [], []
    while t <= T_f + ΔT:
        x = getMB('x', t)
        y = getMB('y', t)
        l_1 = getMB('l_1', t)
        tanf_1 = getMB('tanf_1', t)
        ρ_1 = getAB('ρ_1', t)
        ρ_2 = getAB('ρ_2', t)
        sind_1Minusd_2 = getAB('sin(d_1 - d_2)', t)
        cosd_1Minusd_2 = getAB('cos(d_1 - d_2)', t)

        for i in range(0, 360):
            Q = radians(i)
            ζ = [0, 0]
            cnt = 0
            while True:
                L_1 = l_1 - ζ[cnt] * tanf_1
                ξ = x - L_1 * sin(Q)
                η_1 = (y - L_1 * cos(Q)) / ρ_1
                ζ_1 = sqrt(1 - ξ**2 - η_1**2)

                if ζ_1.imag != 0:
                    break
                
                cnt ^= 1
                ζ[cnt] = ρ_2 * (ζ_1 * cosd_1Minusd_2 - η_1 * sind_1Minusd_2)
                ζ[cnt] = (ζ[cnt] + ζ[cnt ^ 1]) / 2 
                
                if abs(ζ[cnt] - ζ[cnt ^ 1]) < mpf('0.000001'):
                    λ, ϕ = getLongitudeAndLatitude(t, ξ, η_1, ζ_1)
                    ts.append(t)
                    λs.append(λ)
                    ϕs.append(ϕ)
                    break

        t += 𝜏
    
    return ['Outline Curves of the Penumbra', ts, λs, ϕs]

def getOutlineCurvesOfTheUmbra(𝜏):
    t = T_i + ΔT
    ts, λs, ϕs = [], [], []
    while t <= T_f + ΔT:
        x = getMB('x', t)
        y = getMB('y', t)
        l_2 = getMB('l_2', t)
        tanf_2 = getMB('tanf_2', t)
        ρ_1 = getAB('ρ_1', t)
        ρ_2 = getAB('ρ_2', t)
        sind_1Minusd_2 = getAB('sin(d_1 - d_2)', t)
        cosd_1Minusd_2 = getAB('cos(d_1 - d_2)', t)

        for i in range(0, 360, 10):
            Q = radians(i)
            ζ = [0, 0]
            cnt = 0
            while True:
                L_2 = l_2 - ζ[cnt] * tanf_2
                ξ = x - L_2 * sin(Q)
                η_1 = (y - L_2 * cos(Q)) / ρ_1
                ζ_1 = sqrt(1 - ξ**2 - η_1**2)

                if ζ_1.imag != 0:
                    break
                
                cnt ^= 1
                ζ[cnt] = ρ_2 * (ζ_1 * cosd_1Minusd_2 - η_1 * sind_1Minusd_2)
                ζ[cnt] = (ζ[cnt] + ζ[cnt ^ 1]) / 2

                if abs(ζ[cnt] - ζ[cnt ^ 1]) < mpf('0.000001'):
                    λ, ϕ = getLongitudeAndLatitude(t, ξ, η_1, ζ_1)
                    ts.append(t)
                    λs.append(λ)
                    ϕs.append(ϕ)
                    break

        t += 𝜏
    
    return ['Outline Curves of the Umbra', ts, λs, ϕs]

𝜏 = mpf('1') / mpf('30')
printResults(*getRisingAndSettingCurves(𝜏), 2)
printResults(*getCurvesOfMaximumEclipseInTheHorizon(𝜏), 2)
# printResults(*getCentralLine(𝜏), 2)
# printResults(*getNorthernAndSouthernLimitsOfThePenumbra(𝜏), 2)
# printResults(*getNorthernAndSouthernLimitsOfTheUmbra(𝜏), 2)
# printResults(*getOutlineCurvesOfThePenumbra(mpf('1')), 2)
# printResults(*getOutlineCurvesOfTheUmbra(mpf('0.1')), 2)