[Variables]
Background_Width=360
Background_Height=220
Background_Color=20,20,22
Background_Opacity=255
Background_Corner_Round=12
Font_Color=240,240,245
Font_Face=MiSans
Font_Weight=400

; MIUI Orange Theme (Dark Mode)
Accent_Color=255,152,51
Accent_Light=255,180,90
Surface_Color=35,35,38
Surface_Opacity=255
Card_Corner_Round=16
Icon_BG_Color=255,152,51
Icon_BG_Opacity=25

; NightLight Toggle Colors
NightLight_Off_Color=80,80,85
NightLight_Off_Opacity=255
NightLight_Off_Hover_Opacity=230
NightLight_On_Color=255,152,51
NightLight_On_Opacity=255
NightLight_On_Hover_Opacity=230

; Brightness Slider
Slider_Width=280
Slider_Height=6
Slider_X=40
Slider_Track_Color=60,60,65
Slider_Fill_Color=255,152,51
Slider_Thumb_Size=20

;=============================================================
;           MeterStyles
;=============================================================
[NightLight_Shape_Style_0]
This=FillColor #NightLight_Off_Color#,#NightLight_Off_Opacity#
LeftMouseUpAction=[!CommandMeasure Measure_NightLight "Enable"][!UpdateMeter *][!Redraw]
MouseOverAction=[!SetOption #CURRENTSECTION# This "FillColor #NightLight_Off_Color#,#NightLight_Off_Hover_Opacity#"][!UpdateMeter #CURRENTSECTION#][!Redraw]
MouseLeaveAction=[!SetOption #CURRENTSECTION# This "FillColor #NightLight_Off_Color#,#NightLight_Off_Opacity#"][!UpdateMeter #CURRENTSECTION#][!Redraw]

[NightLight_Shape_Style_1]
This=FillColor #NightLight_On_Color#,#NightLight_On_Opacity#
LeftMouseUpAction=[!CommandMeasure Measure_NightLight "Disable"][!UpdateMeter *][!Redraw]
MouseOverAction=[!SetOption #CURRENTSECTION# This "FillColor #NightLight_On_Color#,#NightLight_On_Hover_Opacity#"][!UpdateMeter #CURRENTSECTION#][!Redraw]
MouseLeaveAction=[!SetOption #CURRENTSECTION# This "FillColor #NightLight_On_Color#,#NightLight_On_Opacity#"][!UpdateMeter #CURRENTSECTION#][!Redraw]

[Text_Style]
FontColor=#Font_Color#
FontFace=#Font_Face#
FontWeight=#Font_Weight#
Antialias=1
StringAlign=Left

;=============================================================
;           Content
;=============================================================
[Background_Shape]
Meter=Shape 
Shape=Rectangle 0,0,(#Background_Width#*#Scale#),(#Background_Height#*#Scale#),#Background_Corner_Round# | StrokeWidth 0 | FillColor #Background_Color#,#Background_Opacity# 
DynamicVariables=1

; Brightness Card
[Brightness_Card]
Meter=Shape
X=(20*#Scale#)
Y=(20*#Scale#)
Shape=Rectangle 0,0,((#Background_Width#-40)*#Scale#),(100*#Scale#),#Card_Corner_Round# | StrokeWidth 0 | FillColor #Surface_Color#,#Surface_Opacity#
DynamicVariables=1

[Brightness_Icon_BG]
Meter=Shape
X=(35*#Scale#)
Y=(35*#Scale#)
Shape=Ellipse (20*#Scale#),(20*#Scale#),(20*#Scale#) | Fill Color #Icon_BG_Color#,#Icon_BG_Opacity# | StrokeWidth 0
DynamicVariables=1

[Brightness_Icon]
Meter=Image
ImagePath=#@#Images\Brightness 
ImageName=3.png
X=(45*#Scale#)
Y=(45*#Scale#) 
W=(20*#Scale#)
H=(20*#Scale#)
ImageTint=#Accent_Color#
DynamicVariables=1

[Brightness_Label]
Meter=String
X=(80*#Scale#)
Y=(38*#Scale#)
Text=Brightness
FontSize=(15*#Scale#)
FontWeight=500
MeterStyle=Text_Style
DynamicVariables=1

[Brightness_Value_Text]
Meter=String
X=((#Background_Width#-35)*#Scale#)
Y=(38*#Scale#)
Text=[Measure_Backlight]%
FontSize=(15*#Scale#)
FontWeight=600
FontColor=#Accent_Color#
MeterStyle=Text_Style
StringAlign=Right
DynamicVariables=1

[Brightness_Slider_Track]
Meter=Shape
X=(#Slider_X#*#Scale#)
Y=(90*#Scale#)
Shape=Rectangle 0,0,(#Slider_Width#*#Scale#),(#Slider_Height#*#Scale#),(#Slider_Height#/2*#Scale#) | Fill Color #Slider_Track_Color# | StrokeWidth 0
Shape2=Rectangle 0,0,(Clamp([Slider_Drag_Calc]*[Slider_Size_Calc],0,(#Slider_Width#*#Scale#))),(#Slider_Height#*#Scale#),(#Slider_Height#/2*#Scale#) | Fill Color #Slider_Fill_Color# | StrokeWidth 0
LeftMouseDownAction=[!CommandMeasure Measure_Backlight "SetBacklight $MouseX:%$"][!Update]
DynamicVariables=1

[Brightness_Slider_Thumb]
Meter=Shape
X=(#Slider_X#*#Scale#)
Y=(90*#Scale#)
Shape=Ellipse (#Slider_Thumb_Size#/2*#Scale#),(#Slider_Thumb_Size#/2*#Scale#),(#Slider_Thumb_Size#/2*#Scale#) | Fill Color #Accent_Color# | StrokeWidth (2*#Scale#) | Stroke Color 255,255,255 | Offset (Clamp([Slider_Drag_Calc]*[Slider_Size_Calc],0,(#Slider_Width#*#Scale#))),(-(#Slider_Thumb_Size#/2*#Scale#)+(#Slider_Height#/2*#Scale#))
MouseOverAction=[!CommandMeasure Measure_Mouse_Brightness "Start"]
DynamicVariables=1

; NightLight Card
[NightLight_Card]
Meter=Shape
X=(20*#Scale#)
Y=(140*#Scale#)
Shape=Rectangle 0,0,((#Background_Width#-40)*#Scale#),(60*#Scale#),#Card_Corner_Round# | StrokeWidth 0 | FillColor #Surface_Color#,#Surface_Opacity#
DynamicVariables=1

[NightLight_Icon_BG]
Meter=Shape
X=(35*#Scale#)
Y=(150*#Scale#)
Shape=Ellipse (20*#Scale#),(20*#Scale#),(20*#Scale#) | Fill Color #Icon_BG_Color#,#Icon_BG_Opacity# | StrokeWidth 0
DynamicVariables=1

[NightLight_Icon]
Meter=Image
ImageName=#@#Images\NightLight\[Measure_NightLight].png
X=(45*#Scale#)
Y=(160*#Scale#) 
W=(20*#Scale#)
H=(20*#Scale#)
ImageTint=#Accent_Color#
DynamicVariables=1

[NightLight_Label]
Meter=String
X=(80*#Scale#)
Y=(158*#Scale#)
Text=Night Light
FontSize=(15*#Scale#)
FontWeight=500
MeterStyle=Text_Style
DynamicVariables=1

[NightLight_Toggle]
Meter=Shape 
X=((#Background_Width#-75)*#Scale#)
Y=(158*#Scale#)
Shape=Rectangle 0,0,(46*#Scale#),(26*#Scale#),(13*#Scale#) | StrokeWidth 0 | Extend This
Shape2=Ellipse (13*#Scale#),(13*#Scale#),(10*#Scale#) | Fill Color 255,255,255 | StrokeWidth 0 | Offset ([Measure_NightLight]*20*#Scale#),0
MeterStyle=NightLight_Shape_Style_[Measure_NightLight]
DynamicVariables=1
