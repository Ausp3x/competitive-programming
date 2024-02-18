# -*- coding: utf-8 -*-
"""
Created on Wed Nov  8 07:35:49 2023

@author: Ausp3x
"""

from collections import deque
from mpmath import *
import cartopy
import cartopy.crs as crs
import cartopy.feature as cf
import matplotlib as mpl
import matplotlib.pyplot as plt
import numpy as np
mp.dps = 100
mpl.rcParams['axes.linewidth'] = 10

########################################################################################################################################################################################################
a = mpf('6378136.6')
f = 1 / mpf('298.257222101')
e = sqrt(1 - (1 - f)**2)

name = 'Total Solar Eclipse of 2043 April 09'
TDT, ΔT = mpf('19'), mpf('803/36000')
T_i, T_f = mpf('-5'), mpf('5')
B = {
    'x':      [mpf('-0.44779'), mpf('0.51360'), mpf('0.00006'),  mpf('-0.00001')],
    'y':      [mpf('0.89790'),  mpf('0.26973'), mpf('-0.00009'), mpf('-0.00000')],
    'd':      [mpf('7.7498'),   mpf('0.0148'),  mpf('-0.0000')],
    'μ':      [mpf('104.6151'),  mpf('15.0041'), mpf('-0.0000')],
    'l_1':    [mpf('0.53536'),  mpf('-0.00005'), mpf('-0.00001')],
    'l_2':    [mpf('-0.01074'), mpf('-0.00005'), mpf('-0.00001')],
    'tanf_1': [mpf('0.0046680')],
    'tanf_2': [mpf('0.0046448')],
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
########################################################################################################################################################################################################
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
#             if abs(p[cnt].real - p[cnt ^ 1].real) < mpf('0.000000001'):
#                 return t_0 + p[cnt] * τ
    
#     return None

def successiveApproximation(f, *argv):
    t, τ = [argv[0], 0], mpf('0.000000000000000001')
    cnt = 0
    for i in range(100):
        f_t = f(t[cnt], *argv[1:])
        t[cnt ^ 1] = t[cnt] - f_t / ((f(t[cnt] + τ, *argv[1:]) - f_t) / τ)
        cnt ^= 1
        
        if abs(t[cnt] - t[cnt ^ 1]) < mpf('0.000000001'):
            return t[cnt]
        
    return None
########################################################################################################################################################################################################
def getLongitudeAndLatitude(t, ξ, η_1, ζ_1):
    μ = getMB('μ', t - ΔT)
    sind_1 = getAB('sind_1', t)
    cosd_1 = getAB('cosd_1', t)
    
    ϕ_1 = asin(η_1 * cosd_1 + ζ_1 * sind_1)
    θ = 2 * atan(ξ / (cos(ϕ_1) - η_1 * sind_1 + ζ_1 * cosd_1))
    
    ϕ = atan(tan(ϕ_1) / sqrt(1 - e**2))
    λ = θ - μ
    
    if ϕ.imag != 0 or λ.imag != 0:
        return [None, None]
    
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
    s = int(frac(dur) * 600000)
    
    if s % 10 >= 5:
        s += 10
    s //= 10
    if s >= 60000:
        m += 1
        s -= 60000
        
    return str(m).zfill(2) + 'm' + str(s // 1000).zfill(2) + '.' + str(s % 1000).zfill(3) + 's'

def convertPathWidth(wid):
    wid = abs(wid) * a / 1000
    widInt = int(wid)
    widFrc = int(frac(wid) * 100)
    
    if widFrc % 10 >= 5:
        widFrc += 10
    widFrc //= 10
    if widFrc >= 10:
        widInt += 1
        widFrc -= 10 
        
    return str(widInt).rjust(3) + '.' + str(widFrc) + ' km'
########################################################################################################################################################################################################
file1 = open('General Circumstances.txt', 'w', encoding = 'utf-8')
mag = None
obs = None
genCircs = {}
for k in ['GE', 'EC'
          'P1', 'P2', 'P3', 'P4', 'PN1', 'PS1', 'PN2', 'PS2', 
          'U1', 'U2', 'U3', 'U4', 'UN1', 'US1', 'UN2', 'US2', 
          'C1', 'C2']:
    if k == 'GE' or k == 'C1' or k == 'C2':
        genCircs[k] = [None, None, None, None, None]
    else:
        genCircs[k] = [None, None, None] 
genCircLabels = {
    'GE':  'Greatest Eclipse',
    'EC':  'Equatorial Conjunction',
    
    'P1':  'First External Contact of the Penumbra', 
    'P2':  'First Internal Contact of the Penumbra',
    'P3':  'Last Internal Contact of the Penumbra',
    'P4':  'Last External Contact of the Penumbra',
    'PN1': 'Extreme Northern Limit 1 of the Penumbra',
    'PS1': 'Extreme Southern Limit 1 of the Penumbra',
    'PN2': 'Extreme Northern Limit 2 of the Penumbra',
    'PS2': 'Extreme Southern Limit 2 of the Penumbra',
    
    'U1':  'First External Contact of the Um/Antumbra',
    'U2':  'First Internal Contact of the Um/Antumbra',
    'U3':  'Last Internal Contact of the Um/Antumbra',
    'U4':  'Last External Contact of the Um/Antumbra',
    'UN1': 'Extreme Northern Limit 1 of the Um/Antumbra',
    'US1': 'Extreme Southern Limit 1 of the Um/Antumbra',
    'UN2': 'Extreme Northern Limit 2 of the Um/Antumbra',
    'US2': 'Extreme Southern Limit 2 of the Um/Antumbra',
    
    'C1':  'Extreme Central Line Limit 1',
    'C2':  'Extreme Central Line Limit 2',
}
def printResults1(keys, opt):
    for k in keys:
        t, λ, ϕ = genCircs[k][:3]
        if opt == 1:
            if t == None:
                file1.write('| ' + k.ljust(4) + ' | None        | None       | None        |                         |\n')
                print(f'General Circumstances {k}: '.ljust(27) + 'ok')
                continue
            
            if λ == None:
                file1.write('| ' + k.ljust(4) + ' | ' + convertToUT1(t) + ' | None       | None        |                         |\n')
                print(f'General Circumstances {k}: '.ljust(27) + 'ok')
                continue
            
            file1.write('| ' + k.ljust(4)  + ' | ' + convertToUT1(t) + ' | ' + convertToGeodetic(ϕ, 0) + ' | ' + convertToGeodetic(λ, 1))
            if k == 'GE':
                dur, wid = genCircs[k][3:]
                if dur == None:
                    file1.write(' | None       | None       |\n')
                else:
                    file1.write(' | ' + convertDuration(dur) + ' |  ' + convertPathWidth(wid) + '  |\n')
            else: 
                file1.write(' |                         |\n')
            print(f'General Circumstances {k}: '.ljust(27) + 'ok')
        elif opt == 2:
            if λ == None:
                file1.write('\n')
                continue
            
            file1.write(convertToUT1(t) + ' ' + nstr(degrees(λ), n = 8) + ', ' + nstr(degrees(ϕ), n = 8) + '\n')
        elif opt == 3:
            if λ == None:
                file1.write('\n')
                continue
            
            file1.write(nstr(degrees(λ), n = 8) + ', ' + nstr(degrees(ϕ), n = 8) + '\n')
            
    return
########################################################################################################################################################################################################
file2 = open('Curves.txt', 'w', encoding = 'utf-8')
curves = {}
for k in ['RS', 'MH', 'PN', 'PS', 'UN', 'US', 'CL', 'OP', 'OU']:
    curves[k] = []
curveLabels = {
    'RS': 'Rising and Setting Curves',
    'MH': 'Curves of Maximum Eclipse in the Horizon',
    'PN': 'Northern Limit of the Penumbra',
    'PS': 'Southern Limit of the Penumbra',
    'UN': 'Northern Limit of the Um/Antumbra',
    'US': 'Southern Limit of the Um/Antumbra',
    'CL': 'Central Line',
    'OP': 'Outline Curves of the Penumbra',
    'OU': 'Outline Curves of the Um/Antumbra'
}
def printResults2(keys, opt):
    for k in keys:
        if opt == 1:
            file2.write('+------------------------------------------------------------------+\n')
            file2.write('|' + curveLabels[k].center(66) + '|\n')
            file2.write('+------------------------------------------------------------------+\n')
            
            if k == 'CL':
                isEmpty = True
                for cur in curves[k]:
                    if cur != []:
                        isEmpty = False
                        break
                    
                if isEmpty:
                    file2.write('|' + 'None'.center(66) + '|\n')
                    file2.write('+------------------------------------------------------------------+\n\n')
                    print(f'Curves {k}: ok')
                    continue
                
                file2.write('| Time in UT1 |  Latitude  |  Longitude  |  Duration  | Path Width |\n')
                for cur in curves[k]:
                    if cur == []:
                        continue
                        
                    for t, λ, ϕ, dur, wid in cur:
                        file2.write('| ' + convertToUT1(t) + ' | ' + convertToGeodetic(ϕ, 0) + ' | ' + convertToGeodetic(λ, 1) + ' | ' + convertDuration(dur) + ' |  ' + convertPathWidth(wid) + '  |\n')
                    file2.write('+------------------------------------------------------------------+\n')
                    
                if isEmpty:
                    file2.write('+------------------------------------------------------------------+\n')
                    file2.write('|' + 'None'.center(66) + '|\n')
                    file2.write('+------------------------------------------------------------------+\n')
                    
                file2.write('\n')
                print(f'Curves {k}: ok')
                continue
            
            isEmpty = True
            for cur in curves[k]:
                if cur != [] or cur == deque():
                    isEmpty = False
                    break 
                
            if isEmpty:
                file2.write('|' + 'None'.center(66) + '|\n')
                file2.write('+------------------------------------------------------------------+\n\n')
                print(f'Curves {k}: ok')
                continue
            
            file2.write('|      Time in UT1      |      Latitude      |      Longitude      |\n')
            for cur in curves[k]:
                if cur == [] or cur == deque():
                    continue
                    
                for t, λ, ϕ in cur:
                    file2.write('|      ' + convertToUT1(t) + '      |     ' + convertToGeodetic(ϕ, 0) + '     |     ' + convertToGeodetic(λ, 1) + '     |\n')
                file2.write('+------------------------------------------------------------------+\n')
                
            file2.write('\n')
            print(f'Curves {k}: ok')
        elif opt == 2:
            for cur in curves[k]:
                if cur == []:
                    continue
                
                for loc in cur:
                    t, λ, ϕ = loc[:3]
                    file2.write(convertToUT1(t) + ' ' + nstr(degrees(λ), n = 8) + ', ' + nstr(degrees(ϕ), n = 8) + '\n')
                file2.write('\n')
        elif opt == 3:
            for cur in curves[k]:
                if cur == []:
                    continue
                
                for loc in cur:
                    t, λ, ϕ = loc[:3]
                    file2.write(nstr(degrees(λ), n = 8) + ', ' + nstr(degrees(ϕ), n = 8) + '\n')
                file2.write('\n')
                
    return
########################################################################################################################################################################################################
customLines = [mpl.lines.Line2D([0], [0], color = 'm',       linewidth = 10),
               mpl.lines.Line2D([0], [0], color = 'r',       linewidth = 10),
               mpl.lines.Line2D([0], [0], color = 'g',       linewidth = 10),
               mpl.lines.Line2D([0], [0], color = '#0D98BA', linewidth = 10),
               mpl.lines.Line2D([0], [0], color = 'b',       linewidth = 10),
               mpl.lines.Line2D([0], [0], color = '0.5',     linewidth = 5)]
customLabels = ['Rising and Setting Curves', 'Curves of Maximum Eclipse in the Horizon', 'Northern and Southern Limits of the Penumbra', 'Northern and Southern Limits of the Um/Antumbra', 'Central Line', 'Outline Curves']

def getPlateCarreeProj():
    plt.clf()
    pC = crs.PlateCarree(central_longitude = float(degrees(genCircs['GE'][1])))
    pC._threshold = pC._threshold / 1000000
    ax = plt.axes(projection = pC)
    ax.set_title(name, fontsize = 150, pad = 50)
    ax.add_feature(cf.LAND, color = '#D1FFBD')
    ax.add_feature(cf.OCEAN, color = '#E4F6F8')
    ax.add_feature(cf.LAKES, color = '#E4F6F8')
    ax.add_feature(cf.RIVERS, color = '#E4F6F8', linewidth = 3)
    ax.add_feature(cf.BORDERS, linewidth = 3)
    ax.add_feature(cf.COASTLINE, linewidth = 6)
    
    gl = ax.gridlines(alpha = 0.5, crs = crs.PlateCarree(), draw_labels = True, linestyle = 'dashed', linewidth = 5)
    gl.xformatter = cartopy.mpl.gridliner.LONGITUDE_FORMATTER
    gl.yformatter = cartopy.mpl.gridliner.LATITUDE_FORMATTER
    gl.top_labels = True
    gl.bottom_labels = True
    gl.left_labels = True
    gl.right_labels = True
    gl.xlabel_style = {'bbox' : {'edgecolor' : 'none', 'pad' : 20}, 'linespacing': 1, 'size' : 60}
    gl.ylabel_style = {'bbox' : {'edgecolor' : 'none', 'pad' : 20}, 'linespacing': 1, 'size' : 60}
    
    for k, clr in zip(['OP', 'OU'], ['0.5', '0.5']):
        for cur in curves[k]:
            if cur == []:
                continue
                    
            λs, ϕs = [], []
            for loc in cur:
                λs.append(degrees(loc[1]))
                ϕs.append(degrees(loc[2]))
                
            plt.plot(λs, ϕs, color = clr, linewidth = 3, transform = crs.Geodetic())
            
    for k, clr in zip(['MH', 'RS', 'PN', 'PS', 'UN', 'US', 'CL'], ['r', 'm', 'g', 'g', '#0D98BA', '#0D98BA', 'b']):
        for cur in curves[k]:
            if cur == []:
                continue
            
            λs, ϕs = [], []
            for loc in cur:
                λs.append(degrees(loc[1]))
                ϕs.append(degrees(loc[2]))
                
            plt.plot(λs, ϕs, color = clr, linewidth = 6, transform = crs.Geodetic())
            
    plt.plot(degrees(genCircs['P1'][1]), degrees(genCircs['P1'][2]), color = 'k', marker = '$\\bigoplus$',  markersize = 60, transform = crs.Geodetic())
    plt.plot(degrees(genCircs['GE'][1]), degrees(genCircs['GE'][2]), color = 'k', marker = '$\\bigotimes$', markersize = 60, transform = crs.Geodetic())
    plt.plot(degrees(genCircs['P4'][1]), degrees(genCircs['P4'][2]), color = 'k', marker = '$\\bigodot$',   markersize = 60, transform = crs.Geodetic())
    
    ax.legend(customLines, customLabels, fontsize = 60)
    plt.gcf().set_size_inches(150, 75)
    plt.savefig('Map1.png', bbox_inches = 'tight', pad_inches = 1)
    
    return

def getOrthographicProj():
    plt.clf()
    oc = crs.Orthographic(central_longitude = float(degrees(genCircs['GE'][1])), central_latitude = float(degrees(genCircs['GE'][2])))
    oc._threshold = oc._threshold / 1000000
    ax = plt.axes(projection = oc)
    ax.set_global()
    ax.set_title(name, fontsize = 150, pad = 50)
    ax.add_feature(cf.LAND, color = '#D1FFBD')
    ax.add_feature(cf.OCEAN, color = '#E4F6F8')
    ax.add_feature(cf.LAKES, color = '#E4F6F8')
    ax.add_feature(cf.RIVERS, color = '#E4F6F8', linewidth = 3)
    ax.add_feature(cf.BORDERS, linewidth = 3)
    ax.add_feature(cf.COASTLINE, linewidth = 6)
    
    for k, clr in zip(['OP', 'OU'], ['0.5', '0.5']):
        for cur in curves[k]:
            if cur == []:
                continue
                    
            λs, ϕs = [], []
            for loc in cur:
                λs.append(degrees(loc[1]))
                ϕs.append(degrees(loc[2]))
                
            plt.plot(λs, ϕs, color = clr, linewidth = 3, transform = crs.Geodetic())
            
    for k, clr in zip(['MH', 'RS', 'PN', 'PS', 'UN', 'US', 'CL'], ['r', 'm', 'g', 'g', '#0D98BA', '#0D98BA', 'b']):
        for cur in curves[k]:
            if cur == []:
                continue
            
            λs, ϕs = [], []
            for loc in cur:
                λs.append(degrees(loc[1]))
                ϕs.append(degrees(loc[2]))
                
            plt.plot(λs, ϕs, color = clr, linewidth = 6, transform = crs.Geodetic())
            
    plt.plot(degrees(genCircs['P1'][1]), degrees(genCircs['P1'][2]), color = 'k', marker = '$\\bigoplus$',  markersize = 60, transform = crs.Geodetic())
    plt.plot(degrees(genCircs['GE'][1]), degrees(genCircs['GE'][2]), color = 'k', marker = '$\\bigotimes$', markersize = 60, transform = crs.Geodetic())
    plt.plot(degrees(genCircs['P4'][1]), degrees(genCircs['P4'][2]), color = 'k', marker = '$\\bigodot$',   markersize = 60, transform = crs.Geodetic())
    
    ax.legend(customLines, customLabels, fontsize = 60)
    plt.gcf().set_size_inches(100, 100)
    plt.savefig('Map2.png', bbox_inches = 'tight', pad_inches = 1)
    
    return
########################################################################################################################################################################################################



########################################################################################################################################################################################################
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
            continue
        
        x = getMB('x', t)
        y = getMB('y', t)
        ρ_1 = getAB('ρ_1', t)
        
        y_1 = y / ρ_1
        m_1 = sqrt(x**2 + y_1**2)
        
        λ, ϕ = getLongitudeAndLatitude(t, x / m_1, y_1 / m_1, 0)
        genCircs[k] = [t, λ, ϕ]
        
    return
########################################################################################################################################################################################################
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
            continue
        
        x = getMB('x', t)
        y = getMB('y', t)
        ρ_1 = getAB('ρ_1', t)
        
        y_1 = y / ρ_1 
        m_1 = sqrt(x**2 + y_1**2)
        
        λ, ϕ = getLongitudeAndLatitude(t, x / m_1, y_1 / m_1, 0)
        genCircs[k] = [t, λ, ϕ]

    return
########################################################################################################################################################################################################
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
            continue
        
        x = getMB('x', t)
        y = getMB('y', t)
        ρ_1 = getAB('ρ_1', t)
        l_2 = getMB('l_2', t)
        sind = getMB('sind', t)
        cosd = getMB('cosd', t)
        dx = getMB('dx', t)
        dy = getMB('dy', t)
        dd = getMB('dd', t)
        dμ = getMB('dμ', t)
        ρ_1 = getAB('ρ_1', t)
        
        ξ = x
        η_1 = y / ρ_1
        η = y
        ζ = 0
        
        dξ = dμ * (-y * sind + ζ * cosd)
        dη = dμ * x * sind - dd * ζ
        n = sqrt((dx - dξ)**2 + (dy - dη)**2)
        
        λ, ϕ = getLongitudeAndLatitude(t, ξ, η_1, 0)
        dur = abs(2 * l_2 / n)
        wid = abs(2 * l_2 / sqrt(ζ**2 + ((ξ / n) * (dx - dξ) + (η / n) * (dy - dη))**2))
        genCircs[k] = [t, λ, ϕ, dur, wid]
        
    return
########################################################################################################################################################################################################
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
    # ts = [inverseInterpolation(D_3_1, mpf('-3'), 0), inverseInterpolation(D_3_1, mpf('-3'), 1),
    #       inverseInterpolation(D_3_1, mpf('3'), 0), inverseInterpolation(D_3_1, mpf('3'), 1)]
    ts = [successiveApproximation(D_3_1, T_i, 0), successiveApproximation(D_3_1, T_i, 1),
          successiveApproximation(D_3_1, T_f, 0), successiveApproximation(D_3_1, T_f, 1)]
    for i in range(4):
        if ts[i] == None:
            continue
        
        x = getMB('x', ts[i])
        y = getMB('y', ts[i])
        l_1 = getMB('l_1', ts[i])
        ρ_1 = getAB('ρ_1', ts[i])
        sinQ, cosQ = getSinQCosQPenumbral(ts[i], i % 2)
        
        ξ_1 = x - l_1 * sinQ
        η_1 = (y - l_1 * cosQ) / ρ_1
        
        λ, ϕ = getLongitudeAndLatitude(ts[i], ξ_1, η_1, 0)
        if l_1 * cosQ <= 0:
            genCircs['PN1' if i < 2 else 'PN2'] = [ts[i], λ, ϕ]
        else:
            genCircs['PS1' if i < 2 else 'PS2'] = [ts[i], λ, ϕ]
            
    return
########################################################################################################################################################################################################
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
    # ts = [inverseInterpolation(D_3_2, mpf('-3'), 0), inverseInterpolation(D_3_2, mpf('-3'), 1),
    #       inverseInterpolation(D_3_2, mpf('3'), 0), inverseInterpolation(D_3_2, mpf('3'), 1)]
    ts = [successiveApproximation(D_3_2, T_i, 0), successiveApproximation(D_3_2, T_i, 1),
          successiveApproximation(D_3_2, T_f, 0), successiveApproximation(D_3_2, T_f, 1)]
    for i in range(4):
        if ts[i] == None:
            continue
        
        x = getMB('x', ts[i])
        y = getMB('y', ts[i])
        l_2 = getMB('l_2', ts[i])
        ρ_1 = getAB('ρ_1', ts[i])
        sinQ, cosQ = getSinQCosQUmbral(ts[i], i % 2)
        
        ξ = x - l_2 * sinQ
        η_1 = (y - l_2 * cosQ) / ρ_1
        
        λ, ϕ = getLongitudeAndLatitude(ts[i], ξ, η_1, 0)
        if l_2 * cosQ <= 0:
            genCircs['UN1' if i < 2 else 'UN2'] = [ts[i], λ, ϕ]
        else:
            genCircs['US1' if i < 2 else 'US2'] = [ts[i], λ, ϕ]
            
    return
########################################################################################################################################################################################################
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
    
    y_1 = y / ρ_1
    m_1 = sqrt(x**2 + y_1**2)
    
    if ecl == 1:
        ξ = x / m_1
        η_1 = y_1 / m_1
        ζ_1 = 0
        η = y / m_1
        ζ = 0
        
        Δ = sqrt((x - ξ)**2 + (y - η)**2)
        if genCircs['U1'][0] != None:
            mag = (l_1 - l_2) / (l_1 + l_2)
            obs = mag**2
            
            λ, ϕ = getLongitudeAndLatitude(t, ξ, η_1, ζ_1)
            genCircs['GE'] = [t, λ, ϕ, None, None]
            return
        
        mag = (l_1 - Δ) / (l_1 + l_2)
        
        r_s = 1
        r_m = (l_1 - l_2) / (l_1 + l_2)
        hyp = r_s + r_m - 2 * mag
        A = acos((r_m**2 + hyp**2 - r_s**2) / (2 * r_m * hyp))
        B = acos((r_s**2 + hyp**2 - r_m**2) / (2 * r_s * hyp))
        obs = (r_m**2 * A + r_s**2 * B - r_m**2 * sin(A) * cos(A) - r_s**2 * sin(B) * cos(B)) / pi
        
        λ, ϕ = getLongitudeAndLatitude(t, ξ, η_1, ζ_1)
        genCircs['GE'] = [t, λ, ϕ, None, None]
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
        genCircs['GE'] = [t, λ, ϕ, dur, wid]
        
    return
########################################################################################################################################################################################################
def D_5(t):
    x = getMB('x', t)
    
    return x

def getEquatorialConjunction():
    # t = inverseInterpolation(D_5, mpf('0'))
    t = successiveApproximation(D_5, mpf('0'))
    
    x = getMB('x', t)
    y = getMB('y', t)
    ρ_1 = getAB('ρ_1', t)
    
    y_1 = y / ρ_1
    
    λ, ϕ = getLongitudeAndLatitude(t, x, y_1, 0)
    genCircs['EC'] = [t, λ, ϕ]
    
    return
########################################################################################################################################################################################################



########################################################################################################################################################################################################
def getRisingAndSettingCurvesOfThePenumbra(𝜏):
    t = T_i + ΔT
    curves['RS'].append(deque([genCircs['P1']]))
    curvesInitLen = len(curves['RS'])
    while t <= genCircs['P4'][0]:
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
                    if t > genCircs['P1'][0] and len(curves['RS'][-1]) > 0 and len(curves['RS']) == curvesInitLen:
                        curves['RS'][-1].append(genCircs['P2'])
                        curves['RS'][-1].appendleft(genCircs['P2'])
                        curves['RS'].append(deque([genCircs['P3']]))
                    break
                
                ξ = ρ * sin(γ)
                η_1 = ρ * cos(γ) / ρ_1
                γ2 = 2 * atan(ξ / (η_1 + sqrt(ξ**2 + η_1**2)))
                ρ = sin(γ2) / sin(γ)
                
                if j == cnt - 1:
                    if cos(M - γ) < 0:
                        continue
                    
                    λ, ϕ = getLongitudeAndLatitude(t, sin(γ2), cos(γ2), 0)
                    if i == 0:
                        curves['RS'][-1].append([t, λ, ϕ])
                    else:
                        curves['RS'][-1].appendleft([t, λ, ϕ])
                        
        t += 𝜏
    curves['RS'][-1].append(genCircs['P4'])
    curves['RS'][-1].appendleft(genCircs['P4'])
    
    return
########################################################################################################################################################################################################
def getRisingAndSettingCurvesOfTheUmbra(𝜏):
    if genCircs['U1'][0] == None:
        return
    
    t = T_i + ΔT
    curves['RS'].append(deque([genCircs['U1']]))
    curvesInitLen = len(curves['RS'])
    while t <= genCircs['U4'][0]:
        x = getMB('x', t)
        y = getMB('y', t)
        l_2 = getMB('l_2', t)
        ρ_1 = getAB('ρ_1', t)
        m = sqrt(x**2 + y**2)
        M = 2 * atan(x / (y + m))
        
        for i in range(2):
            ρ = 1
            cnt = 5
            for j in range(cnt):
                A = 2 * asin(sqrt((l_2 + m - ρ) * (l_2 - m + ρ) / (4 * m * ρ)))
                γ = M + pow(-1, i) * A
                        
                if γ.imag != 0:
                    if t > genCircs['U1'][0] and len(curves['RS'][-1]) > 0 and len(curves['RS']) == curvesInitLen:
                        curves['RS'][-1].append(genCircs['U2'])
                        curves['RS'][-1].appendleft(genCircs['U2'])
                        curves['RS'].append(deque([genCircs['U3']]))
                    break
                
                ξ = ρ * sin(γ)
                η_1 = ρ * cos(γ) / ρ_1
                γ2 = 2 * atan(ξ / (η_1 + sqrt(ξ**2 + η_1**2)))
                ρ = sin(γ2) / sin(γ)
                
                if j == cnt - 1:
                    if cos(M - γ) < 0:
                        continue
                    
                    λ, ϕ = getLongitudeAndLatitude(t, sin(γ2), cos(γ2), 0)
                    if i == 0:
                        curves['RS'][-1].append([t, λ, ϕ])
                    else:
                        curves['RS'][-1].appendleft([t, λ, ϕ])
                        
        t += 𝜏
    curves['RS'][-1].append(genCircs['U4'])
    curves['RS'][-1].appendleft(genCircs['U4'])
    
    return
########################################################################################################################################################################################################
def getCurvesOfMaximumEclipseInTheHorizon(𝜏):
    t = T_i + ΔT
    curves['MH'].append(deque())
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
        
        hasNoPoint = True
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
                    if i == 0:
                        curves['MH'][-1].append([t, λ, ϕ])
                    else:
                        curves['MH'][-1].appendleft([t, λ, ϕ])
                        
                    hasNoPoint = False
                    
        if hasNoPoint and len(curves['MH'][-1]) > 0 and len(curves['MH']) == 1:
            curves['MH'][-1] = list(curves['MH'][-1])
            curves['MH'].append(deque())
            
        t += 𝜏
    curves['MH'][-1] = list(curves['MH'][-1])
    
    if curves['MH'][-1] == []:
        curves['MH'].pop()
        
    bor, mxD = -1, mpf('1/12')
    for i in range(len(curves['MH'][-1]) - 1):
        if abs(curves['MH'][-1][i + 1][0] - curves['MH'][-1][i][0]) > mxD:
            bor = i
            mxD = abs(curves['MH'][-1][i + 1][0] - curves['MH'][-1][i][0])
            
    curves['MH'][-1] = curves['MH'][-1][bor+1:] + curves['MH'][-1][:bor + 1]
    
    end = []
    for k in ['PN1', 'PS1', 'PN2', 'PS2']:
        if genCircs[k][0] == None:
            continue
            
        end.append(genCircs[k])
        
    end.sort()
    
    for i in range(len(curves['MH'])):
        if curves['MH'][i][0][0] > curves['MH'][i][-1][0]:
            curves['MH'][i].reverse()
            
        curves['MH'][i] = [end[2 * i]] + curves['MH'][i]
        curves['MH'][i] += [end[2 * i + 1]]
        
    return
########################################################################################################################################################################################################
def getCentralLine(𝜏):
    t = T_i + ΔT
    curves['CL'].append([genCircs['C1']] if genCircs['C1'][0] != None else [])
    while t <= T_f + ΔT:
        x = getMB('x', t)
        y = getMB('y', t)
        ρ_1 = getAB('ρ_1', t)
        l_2 = getMB('l_2', t)
        sind = getMB('sind', t)
        cosd = getMB('cosd', t)
        tanf_2 = getMB('tanf_2', t)
        dx = getMB('dx', t)
        dy = getMB('dy', t)
        dd = getMB('dd', t)
        dμ = getMB('dμ', t)
        ρ_1 = getAB('ρ_1', t)
        ρ_2 = getAB('ρ_2', t)
        sind_1Minusd_2 = getAB('sin(d_1 - d_2)', t)
        cosd_1Minusd_2 = getAB('cos(d_1 - d_2)', t)
        
        ξ = x
        η_1 = y / ρ_1
        ζ_1 = sqrt(1 - ξ**2 - η_1**2) 
        η = y
        ζ = ρ_2 * (ζ_1 * cosd_1Minusd_2 - η_1 * sind_1Minusd_2)
        
        if ζ_1.imag != 0:
            t += 𝜏
            continue
        
        L_2 = l_2 - ζ * tanf_2
        dξ = dμ * (-y * sind + ζ * cosd)
        dη = dμ * x * sind - dd * ζ
        n = sqrt((dx - dξ)**2 + (dy - dη)**2)
        
        λ, ϕ = getLongitudeAndLatitude(t, ξ, η_1, ζ_1)
        dur = abs(2 * L_2 / n)
        wid = abs(2 * L_2 / sqrt(ζ**2 + ((ξ / n) * (dx - dξ) + (η / n) * (dy - dη))**2))
        curves['CL'][-1].append([t, λ, ϕ, dur, wid])
        
        t += 𝜏
    if genCircs['C2'][0] != None:
        curves['CL'][-1].append(genCircs['C2'])
        
    return
########################################################################################################################################################################################################
def getNorthernAndSouthernLimitsOfThePenumbra(𝜏):
    t = T_i + ΔT
    curves['PN'].append([genCircs['PN1']] if genCircs['PN1'][0] != None else [])
    curves['PS'].append([genCircs['PS1']] if genCircs['PS1'][0] != None else [])
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
                
                if abs(ζ[cnt] - ζ[cnt ^ 1]) < mpf('0.000000001'):
                    λ, ϕ = getLongitudeAndLatitude(t, ξ, η_1, ζ_1)
                    if L_1 * cosQ <= 0:
                        curves['PN'][-1].append([t, λ, ϕ])
                    else:
                        curves['PS'][-1].append([t, λ, ϕ])
                    break
                
        t += 𝜏
    if genCircs['PN2'][0]: 
        curves['PN'][-1].append(genCircs['PN2'])
    if genCircs['PS2'][0]: 
        curves['PS'][-1].append(genCircs['PS2'])
        
    return
########################################################################################################################################################################################################
def getNorthernAndSouthernLimitsOfTheUmbra(𝜏):
    t = T_i + ΔT
    curves['UN'].append([genCircs['UN1']] if genCircs['UN1'][0] != None else [])
    curves['US'].append([genCircs['US1']] if genCircs['US1'][0] != None else [])
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
                
                if abs(ζ[cnt] - ζ[cnt ^ 1]) < mpf('0.000000001'):
                    λ, ϕ = getLongitudeAndLatitude(t, ξ, η_1, ζ_1)
                    if L_2 * cosQ <= 0:
                        curves['UN'][-1].append([t, λ, ϕ])
                    else:
                        curves['US'][-1].append([t, λ, ϕ])
                    break
                
        t += 𝜏
    if genCircs['UN2'][0]: 
        curves['UN'][-1].append(genCircs['UN2'])
    if genCircs['US2'][0]: 
        curves['US'][-1].append(genCircs['US2'])
        
    return
########################################################################################################################################################################################################
def getOutlineCurvesOfThePenumbra(𝜏):
    t = T_i + ΔT
    while t <= T_f + ΔT:
        x = getMB('x', t)
        y = getMB('y', t)
        l_1 = getMB('l_1', t)
        tanf_1 = getMB('tanf_1', t)
        ρ_1 = getAB('ρ_1', t)
        ρ_2 = getAB('ρ_2', t)
        sind_1Minusd_2 = getAB('sin(d_1 - d_2)', t)
        cosd_1Minusd_2 = getAB('cos(d_1 - d_2)', t)
        
        curves['OP'].append([])
        hasPoint = [False for _ in range(3600)]
        for i in range(-1, 3600):
            Q = radians((i % 3600) / 10)
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
                
                if abs(ζ[cnt] - ζ[cnt ^ 1]) < mpf('0.000000001'):
                    λ, ϕ = getLongitudeAndLatitude(t, ξ, η_1, ζ_1)
                    curves['OP'][-1].append([t, λ, ϕ])
                    hasPoint[i] = True
                    break
                
            if i >= 0 and hasPoint[i - 1] and not hasPoint[i]:
                ii, itr, loc = i - 1, mpf('0.5'), curves['OP'][-1][-1]
                while itr >= mpf('0.000000001'):
                    Q = radians((ii + itr) / 10)
                    ζ = [0, 0]
                    cnt = 0
                    curHasPoint = False
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
                        
                        if abs(ζ[cnt] - ζ[cnt ^ 1]) < mpf('0.000000001'):
                            curHasPoint = True
                            λ, ϕ = getLongitudeAndLatitude(t, ξ, η_1, ζ_1)
                            loc = [t, λ, ϕ]
                            break
                        
                    if curHasPoint == True:
                        ii += itr
                        
                    itr /= 2
                    
                curves['OP'][-1].append(loc)
                curves['OP'].append([])
            elif i >= 0 and not hasPoint[i - 1] and hasPoint[i]:
                ii, itr, loc = i, mpf('0.5'), curves['OP'][-1][-1]
                while itr >= mpf('0.000000001'):
                    Q = radians((ii - itr) / 10)
                    ζ = [0, 0]
                    cnt = 0
                    curHasPoint = False
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
                        
                        if abs(ζ[cnt] - ζ[cnt ^ 1]) < mpf('0.000000001'):
                            curHasPoint = True
                            λ, ϕ = getLongitudeAndLatitude(t, ξ, η_1, ζ_1)
                            loc = [t, λ, ϕ]
                            break
                        
                    if curHasPoint == True:
                        ii -= itr
                        
                    itr /= 2
                    
                curves['OP'][-1].insert(-1, loc)
                
        t += 𝜏
        
    return
########################################################################################################################################################################################################
def getOutlineCurvesOfTheUmbra(𝜏):
    t = T_i + ΔT
    while t <= T_f + ΔT:
        x = getMB('x', t)
        y = getMB('y', t)
        l_2 = getMB('l_2', t)
        tanf_2 = getMB('tanf_2', t)
        ρ_1 = getAB('ρ_1', t)
        ρ_2 = getAB('ρ_2', t)
        sind_1Minusd_2 = getAB('sin(d_1 - d_2)', t)
        cosd_1Minusd_2 = getAB('cos(d_1 - d_2)', t)
        
        curves['OU'].append([])
        hasPoint = [False for _ in range(360)]
        for i in range(-1, 360):
            Q = radians(i % 360)
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
                
                if abs(ζ[cnt] - ζ[cnt ^ 1]) < mpf('0.000000001'):
                    λ, ϕ = getLongitudeAndLatitude(t, ξ, η_1, ζ_1)
                    curves['OU'][-1].append([t, λ, ϕ])
                    hasPoint[i] = True
                    break
                
            if i >= 0 and hasPoint[i - 1] and not hasPoint[i]:
                ii, itr, loc = i - 1, mpf('0.5'), curves['OU'][-1][-1]
                while itr >= mpf('0.000000001'):
                    Q = radians(ii + itr)
                    ζ = [0, 0]
                    cnt = 0
                    curHasPoint = False
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
                        
                        if abs(ζ[cnt] - ζ[cnt ^ 1]) < mpf('0.000000001'):
                            curHasPoint = True
                            λ, ϕ = getLongitudeAndLatitude(t, ξ, η_1, ζ_1)
                            loc = [t, λ, ϕ]
                            break
                        
                    if curHasPoint == True:
                        ii += itr
                        
                    itr /= 2
                    
                curves['OU'][-1].append(loc)
                curves['OU'].append([])
            elif i >= 0 and not hasPoint[i - 1] and hasPoint[i]:
                ii, itr, loc = i, mpf('0.5'), curves['OU'][-1][-1]
                while itr >= mpf('0.000000001'):
                    Q = radians(ii - itr)
                    ζ = [0, 0]
                    cnt = 0
                    curHasPoint = False
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
                        
                        if abs(ζ[cnt] - ζ[cnt ^ 1]) < mpf('0.000000001'):
                            curHasPoint = True
                            λ, ϕ = getLongitudeAndLatitude(t, ξ, η_1, ζ_1)
                            loc = [t, λ, ϕ]
                            break
                        
                    if curHasPoint == True:
                        ii -= itr
                        
                    itr /= 2
                    
                curves['OU'][-1].insert(-1, loc)
                
        t += 𝜏
    
    return
########################################################################################################################################################################################################



########################################################################################################################################################################################################
getFirstAndLastContactsOfPenumbra()
getFirstAndLastContactsOfUmbra()
getBeginningAndEndOfCentralLine()
getExtremePointsOfPenumbralLimits()
getExtremePointsOfUmbralLimits()
getGreatestEclipse(1 if genCircs['C1'][0] == None else 2)
getEquatorialConjunction()

file1.write(('General Circumstances of the ' + name).center(75) + '\n')
file1.write('+-------------------------------------------------------------------------+\n')
if mag.imag == 0:
    file1.write('| Eclipse Magnitude   | ' + nstr(mag).ljust(8) + '                                          |\n')
else:
    file1.write('| Eclipse Magnitude   | None                                              |\n')
if obs.imag == 0:
    file1.write('| Eclipse Obscuration | ' + nstr(obs).ljust(8) + '                                          |\n')
else:
    file1.write('| Eclipse Obscuration | None                                              |\n')
file1.write('+-------------------------------------------------------------------------+\n')
file1.write('| Name | Time in UT1 |  Latitude  |  Longitude  |  Duration  | Path Width |\n')
printResults1(['GE', 'EC', 'P1', 'P2', 'P3', 'P4', 'PN1', 'PS1', 'PN2', 'PS2', 'U1', 'U2', 'U3', 'U4', 'UN1', 'US1', 'UN2', 'US2', 'C1', 'C2'], 1)
file1.write('+-------------------------------------------------------------------------+\n')
# printResults1(['GE', 'EC', 'P1', 'P2', 'P3', 'P4', 'PN1', 'PS1', 'PN2', 'PS2', 'U1', 'U2', 'U3', 'U4', 'UN1', 'US1', 'UN2', 'US2', 'C1', 'C2'], 3)

𝜏 = mpf('1/120')
getRisingAndSettingCurvesOfThePenumbra(𝜏)
getRisingAndSettingCurvesOfTheUmbra(𝜏 / 10)
getCurvesOfMaximumEclipseInTheHorizon(𝜏 / 10)
getCentralLine(𝜏)
getNorthernAndSouthernLimitsOfThePenumbra(𝜏)
getNorthernAndSouthernLimitsOfTheUmbra(𝜏)
getOutlineCurvesOfThePenumbra(mpf('1'))
getOutlineCurvesOfTheUmbra(mpf('0.1'))

file2.write(('Curves of the ' + name).center(68) + '\n')
printResults2(['RS', 'MH', 'PN', 'PS', 'UN', 'US', 'CL', 'OP', 'OU'], 1)
# printResults2(['RS', 'MH', 'PN', 'PS', 'UN', 'US', 'CL', 'OP', 'OU'], 3)

getPlateCarreeProj()
getOrthographicProj()
########################################################################################################################################################################################################