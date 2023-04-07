package com.example.startservices;

import androidx.appcompat.app.AppCompatActivity;

import android.content.Intent;
import android.media.MediaPlayer;
import android.os.Bundle;
import android.provider.Settings;
import android.widget.Button;

public class MainActivity extends AppCompatActivity {
    MediaPlayer player;
    Button btnPlay, btnStop, btnSV, btnStopSV;
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        setTitle("Play the ringtone");

        btnPlay =(Button) findViewById(R.id.btnPlay);
        btnStop =(Button) findViewById(R.id.btnStop);
        btnSV =(Button) findViewById(R.id.btnSV);
        btnStopSV =(Button) findViewById(R.id.btnStopSV);

        btnPlay.setOnClickListener(view -> {
            player = MediaPlayer.create(MainActivity.this, Settings.System.DEFAULT_RINGTONE_URI);
            player.setLooping(true);
            player.start();
        });

        btnStop.setOnClickListener(view -> player.stop());

        btnSV.setOnClickListener(view -> startService(new Intent(MainActivity.this, MyService.class)));

        btnStopSV.setOnClickListener(view -> stopService(new Intent(MainActivity.this, MyService.class)));
    }
}