[Variables]
Background_Width=380
Background_Height=250
Background_Color=25,25,28
Background_Opacity=255
Background_Corner_Round=14
Font_Color=230,230,235
Font_Face=Google Sans
Font_Weight=400

; Pixel Material You Colors (Dark Mode)
Accent_Color=179,157,219
Accent_Light=208,188,255
Surface_Color=45,45,50
Surface_Opacity=255
Card_Corner_Round=24

; NightLight Toggle Colors
NightLight_Off_Color=120,120,130
NightLight_Off_Opacity=30
NightLight_Off_Hover_Opacity=50
NightLight_On_Color=103,80,164
NightLight_On_Opacity=255
NightLight_On_Hover_Opacity=230

; Brightness Slider
Slider_Width=280
Slider_Height=8
Slider_X=40
Slider_Track_Color=70,70,80
Slider_Fill_Color=179,157,219
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

[Card_Style]
Shape=Rectangle 0,0,(#Background_Width#-40*#Scale#),(90*#Scale#),#Card_Corner_Round# | StrokeWidth 0 | FillColor #Surface_Color#,#Surface_Opacity#

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
MeterStyle=Card_Style
DynamicVariables=1

[Brightness_Icon]
Meter=Image
ImagePath=#@#Images\Brightness 
ImageName=3.png
X=(40*#Scale#)
Y=(30*#Scale#) 
W=(40*#Scale#)
H=(40*#Scale#)
ImageTint=#Accent_Color#
DynamicVariables=1

[Brightness_Label]
Meter=String
X=(95*#Scale#)
Y=(35*#Scale#)
Text=Brightness
FontSize=(16*#Scale#)
FontWeight=500
MeterStyle=Text_Style
DynamicVariables=1

[Brightness_Value_Text]
Meter=String
X=((#Background_Width#-40)*#Scale#)
Y=(35*#Scale#)
Text=[Measure_Backlight]%
FontSize=(16*#Scale#)
FontWeight=500
FontColor=#Accent_Color#
MeterStyle=Text_Style
StringAlign=Right
DynamicVariables=1

[Brightness_Slider]
Meter=Shape
X=(#Slider_X#*#Scale#)
Y=(85*#Scale#)
Shape=Rectangle 0,0,(#Slider_Width#*#Scale#),(#Slider_Height#*#Scale#),(#Slider_Height#/2*#Scale#) | Fill Color #Slider_Track_Color# | StrokeWidth 0
Shape2=Rectangle 0,0,(Clamp([Slider_Drag_Calc]*[Slider_Size_Calc],0,(#Slider_Width#*#Scale#))),(#Slider_Height#*#Scale#),(#Slider_Height#/2*#Scale#) | Fill Color #Slider_Fill_Color# | StrokeWidth 0
Shape3=Ellipse (#Slider_Thumb_Size#/2*#Scale#),(#Slider_Thumb_Size#/2*#Scale#),(#Slider_Thumb_Size#/2*#Scale#) | Fill Color #Accent_Color# | StrokeWidth (3*#Scale#) | Stroke Color 255,255,255 | Offset (Clamp([Slider_Drag_Calc]*[Slider_Size_Calc],0,(#Slider_Width#*#Scale#))),(-(#Slider_Thumb_Size#/2*#Scale#)+(#Slider_Height#/2*#Scale#))
LeftMouseDownAction=[!CommandMeasure Measure_Backlight "SetBacklight $MouseX:%$"][!Update]
MouseOverAction=[!CommandMeasure Measure_Mouse_Brightness "Start"]
DynamicVariables=1

; NightLight Card
[NightLight_Card]
Meter=Shape
X=(20*#Scale#)
Y=(130*#Scale#)
MeterStyle=Card_Style
DynamicVariables=1

[NightLight_Icon]
Meter=Image
ImageName=#@#Images\NightLight\[Measure_NightLight].png
X=(40*#Scale#)
Y=(150*#Scale#) 
W=(40*#Scale#)
H=(40*#Scale#)
ImageTint=#Accent_Color#
DynamicVariables=1

[NightLight_Label]
Meter=String
X=(95*#Scale#)
Y=(160*#Scale#)
Text=Night Light
FontSize=(16*#Scale#)
FontWeight=500
MeterStyle=Text_Style
DynamicVariables=1

[NightLight_Toggle_Track]
Meter=Shape 
X=((#Background_Width#-90)*#Scale#)
Y=(158*#Scale#)
Shape=Rectangle 0,0,(52*#Scale#),(28*#Scale#),(14*#Scale#) | StrokeWidth 0 | Extend This
MeterStyle=NightLight_Shape_Style_[Measure_NightLight]
DynamicVariables=1

[NightLight_Toggle_Thumb]
Meter=Shape
X=((#Background_Width#-90)*#Scale#)
Y=(158*#Scale#)
Shape=Ellipse (14*#Scale#),(14*#Scale#),(10*#Scale#) | Fill Color 255,255,255 | StrokeWidth 0 | Offset ([Measure_NightLight]*24*#Scale#),0
DynamicVariables=1
