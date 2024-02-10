from mpmath import *
mp.dps = 100

# Partial Solar Eclipse of 2022 April 30
TDT, ΔT = mpf('21'), mpf('70.7') / mpf('3600')
T_i, T_f = mpf('-5'), mpf('5')
B = {
     'x':      [mpf('0.61808'),  mpf('0.47531'), mpf('-0.00000'), mpf('-0.00001')],
     'y':      [mpf('-1.02809'), mpf('0.20964'), mpf('-0.00004'), mpf('-0.00000')],
     'd':      [mpf('14.9710'),  mpf('0.0122'),  mpf('-0.0000')],
     'μ':      [mpf('135.7056'), mpf('15.0025'), mpf('-0.0000')],
     'l_1':    [mpf('0.56109'),  mpf('0.00008'), mpf('-0.00001')],
     'l_2':    [mpf('0.01486'),  mpf('0.00008'), mpf('-0.00001')],
     'tanf_1': [mpf('0.0046420')],
     'tanf_2': [mpf('0.0046189')],
    }

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

# Hybrid Solar Eclipse of 2023 April 20
TDT, ΔT = mpf('4'), mpf('71.1') / mpf('3600')
T_i, T_f = mpf('-5'), mpf('5')
B = {
     'x':      [mpf('0.02685'),  mpf('0.49502'), mpf('0.00001'),  mpf('-0.00001')],
     'y':      [mpf('-0.42737'), mpf('0.24420'), mpf('-0.00005'), mpf('0.00000')],
     'd':      [mpf('11.4118'),  mpf('0.0137'),  mpf('-0.0000')],
     'μ':      [mpf('240.2429'), mpf('15.0034'), mpf('-0.0000')],
     'l_1':    [mpf('0.54682'),  mpf('0.00012'), mpf('-0.00001')],
     'l_2':    [mpf('0.00066'),  mpf('0.00012'), mpf('-0.00001')],
     'tanf_1': [mpf('0.0046550')],
     'tanf_2': [mpf('0.0046318')],
    }

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

# Total Solar Eclipse of 2024 April 08
TDT, ΔT = mpf('18'), mpf('715/36000')
T_i, T_f = mpf('-5'), mpf('5')
B = {
     'x':      [mpf('-0.31825'), mpf('0.51171'), mpf('0.00003'),  mpf('-0.00001')],
     'y':      [mpf('0.21976'),  mpf('0.27096'), mpf('-0.00006'), mpf('-0.00000')],
     'd':      [mpf('7.5862'),   mpf('0.0148'),  mpf('-0.0000')],
     'μ':      [mpf('89.5912'),  mpf('15.0041'), mpf('-0.0000')],
     'l_1':    [mpf('0.53583'),  mpf('0.00006'), mpf('-0.00001')],
     'l_2':    [mpf('-0.01027'), mpf('0.00006'), mpf('-0.00001')],
     'tanf_1': [mpf('0.0046683')],
     'tanf_2': [mpf('0.0046450')],
    }