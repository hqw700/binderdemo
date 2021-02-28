package demo;

import android.os.Parcel;
import android.os.Parcelable;

public class BinderData implements Parcelable {
    private String name;

    @Override
    public int describeContents() {
        return 0;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    @Override
    public void writeToParcel(Parcel dest, int flags) {
        dest.writeString(this.name);
    }

    public void readFromParcel(Parcel source) {
        this.name = source.readString();
    }

    public BinderData() {
    }

    protected BinderData(Parcel in) {
        this.name = in.readString();
    }

    public static final Parcelable.Creator<BinderData> CREATOR = new Parcelable.Creator<BinderData>() {
        @Override
        public BinderData createFromParcel(Parcel source) {
            return new BinderData(source);
        }

        @Override
        public BinderData[] newArray(int size) {
            return new BinderData[size];
        }
    };
}
