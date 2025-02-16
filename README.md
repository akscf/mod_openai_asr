<p>
  OpenAI Speech-To-Text service for the Freeswitch. <br>
  Available through: asr_interface, cammnad api <br>
</p>

### Dialplan example
```XML
<extension name="openai-asr">
  <condition field="destination_number" expression="^(3222)$">
    <action application="answer"/>
    <action application="play_and_detect_speech" data="/tmp/test2.wav detect:openai"/>
    <action application="sleep" data="1000"/>
    <action application="log" data="CRIT SPEECH_RESULT=${detect_speech_result}"/>
    <action application="hangup"/>
 </condition>
</extension>
```

### Command line
```
freeswitch> openai_asr_transcribe /tmp/test.[wav|mp3] [key=altKey mode=altModel]
+OK: How old is the Brooklyn Bridge
```
