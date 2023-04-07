package com.example.kiemtra;

import android.content.Context;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.ArrayAdapter;
import android.widget.TextView;

import androidx.annotation.NonNull;
import androidx.annotation.Nullable;

import java.util.List;

public class VeTauAdapter extends ArrayAdapter<VeTau> {
        public VeTauAdapter(@NonNull Context context, int resource) {
            super(context, resource);
        }

        public VeTauAdapter(@NonNull Context context, int resource, int textViewResourceId) {
            super(context, resource, textViewResourceId);
        }

        public VeTauAdapter(@NonNull Context context, int resource, @NonNull List<VeTau> objects) {
            super(context, resource, objects);
        }

        @NonNull
        @Override
        public View getView(int position, @Nullable View convertView, @NonNull ViewGroup parent) {
            View v = convertView;
            if(v == null) {
                LayoutInflater vi;
                vi = LayoutInflater.from(getContext());
                v = vi.inflate(R.layout.activity_list_view_item, null);
            }
            VeTau vt = getItem(position);
            if(vt != null) {
                // anh xa
                TextView tt1 = (TextView) v.findViewById(R.id.textViewNoiDen);
                TextView tt2 = (TextView) v.findViewById(R.id.textViewNoiDi);
                TextView tt3 = (TextView) v.findViewById(R.id.textViewKieuVe);
                TextView tt4 = (TextView) v.findViewById(R.id.textViewGia);
                // gan gia tri
                tt1.setText(vt.NoiDen);
                tt2.setText(vt.NoiDi);
                tt3.setText(vt.KieuVe);
                tt4.setText(String.valueOf(vt.DonGia));
            }
         return v;
        }
    }
